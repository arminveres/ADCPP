#pragma once
#include <iostream>

template<typename F>
struct player {

	int ID;

	bool AI;
	int bruteForceStrategy[F::width] = { 0 };

	enum class Prio {
		HighPrio = 3,
		MediumPrio = 2,
		LowPrio = 1
	};

	int AILogic(F field) {
		int columnProposal[F::width] = { 0 };

		//if player can win (higher priority to check)
		ifAlreadyThreeStones(field, columnProposal, F::player1);
		
		//if AI can win
		ifAlreadyThreeStones(field, columnProposal, F::player2);
		//try to win vertically
		ifAlreadyStoneSet(field, columnProposal);

		return makeFinalDesicion(columnProposal);
	};


	void ifAlreadyThreeStones(F field, int columnProposal[], char player) {

		//vertical - if player can win
		for (int column = 0; column < F::width; column++) {
			for (int row = 0; row < F::height; row++) {
				if (row == 0 && field.rep[column][row] != F::none) { // column is full
					break;
				}
				if (field.rep[column][row] == player) {
					//if player can win vertically
					if (field.rep[column][row + 1] == player && field.rep[column][row + 2] == player && (row - 1) >= 0 && field.rep[column][row - 1] == F::none) {
						if (player == F::player1) {
							columnProposal[column] = columnProposal[column] + (int)Prio::MediumPrio; //when enemy could win
						}
						else {
							columnProposal[column] = columnProposal[column] + (int)Prio::HighPrio; // when AI can win
						}
					}
				}
			}
		}

		//horizontal - if player can win
		for (int row = 0; row < F::height; row++) {
			for (int column = 0; column < F::width; column++) {
				if (field.rep[column][row] == player) {
					if (field.rep[column + 1][row] == player && field.rep[column + 2][row] == player) { //if player can win horizontally
						int leftDepthMissing = F::height + 1;
						int rightDepthMissing = F::height + 1;
						if ((column + 1) < F::width && field.rep[column + 3][row] == F::none) { //is there enought space to the right?
							rightDepthMissing = depthMissing(field, column, row + 1);

						}
						if (column - 1 >= 0 && field.rep[column - 1][row] == F::none) { //is there enought space to the left?
							leftDepthMissing = depthMissing(field, column, row + 1);
						}
						if (leftDepthMissing <= rightDepthMissing) { //how many stones do you have to fill up first 
							if (player == F::player2 || (player == F::player1 && leftDepthMissing == 0)) { //left side
								if (player == F::player2) {
									columnProposal[column - 1] = columnProposal[column - 1] + (int)Prio::HighPrio;

								}
								else {
									columnProposal[column - 1] = columnProposal[column - 1] + (int)Prio::MediumPrio;
								}
							}
						}
						else if (player == F::player2 || (player == F::player1 && rightDepthMissing == 0)) { //ride side
							if (player == F::player1) {
								columnProposal[column + 3] = columnProposal[column + 3] + (int)Prio::MediumPrio;
							}
							else {
								columnProposal[column + 3] = columnProposal[column + 3] + (int)Prio::HighPrio;
							}
						}
					}
					if (field.rep[column + 3][row] == player) { // if player can win horizontally but stone is missing in middle
						if (field.rep[column + 1][row] == F::none && field.rep[column + 2][row] == player) {
							if (player == F::player2 || (player == F::player1 && depthMissing(field, column, row + 1) == 0)) {
								if (player == F::player1) {
									columnProposal[column + 1] = columnProposal[column + 1] + (int)Prio::MediumPrio;
								}
								else {
									columnProposal[column + 1] = columnProposal[column + 1] + (int)Prio::HighPrio;
								}
							}
						}
						else if (field.rep[column + 2][row] == F::none && field.rep[column + 1][row] == player) {
							if (player == F::player2 || (player == F::player1 && depthMissing(field, column, row + 1) == 0)) {
								if (player == F::player1) {
									columnProposal[column + 2] = columnProposal[column + 2] + (int)Prio::MediumPrio;
								}
								else {
									columnProposal[column + 2] = columnProposal[column + 2] + (int)Prio::HighPrio;
								}
							}
						}
					}
				}
			}
		}
	}

	void ifAlreadyStoneSet(F field, int columnProposal[]) {
		for (int column = 0; column < F::width; column++) {
			if (bruteForceStrategy[column] == 1) {
				for (int row = 0; row < F::height; row++) {
					if (field.stoneat(column, row) == F::player2) {
						//there's two space left, and two stones are already set
						if (((row - 2) >= 0) && ((row + 1) < F::height) && field.stoneat(column, row + 1) == F::player2 && field.stoneat(column, row - 1) == F::none) {
							columnProposal[column] = columnProposal[column] + (int)Prio::LowPrio;
							break;
						}
						//there's 3 space left, and one stone is already set
						if (((row - 3) >= 0) && field.stoneat(column, row - 1) == F::none) {
							columnProposal[column] = columnProposal[column] + (int)Prio::LowPrio;
							break;
						}
						else {
							break;
						}
					}
				}
			}
		}
	}

	int makeFinalDesicion(int columnProposal[]) {
		//choose column with the highest victory chance
		const int INIT = -1;
		int lockedColumn = INIT;
		int lockedAmountPriority = 0;
		for (int column = 0; column < F::width; column++) {
			int amountPriority = columnProposal[column];
			if (amountPriority > lockedAmountPriority) {
				lockedColumn = column;
				lockedAmountPriority = amountPriority;
			}
		}
		if (lockedColumn == INIT) {
			lockedColumn = std::rand() % (F::width - 1) + 1; //pick random
			if (bruteForceStrategy[lockedColumn] == 1) { //if we're here in random section, it means previous bruteForce column failed, so delete it
				int oldCol = lockedColumn;
				while (lockedColumn == oldCol) {
					lockedColumn = std::rand() % (F::width - 1) +1;
				}
				bruteForceStrategy[oldCol] = 0;
			}
			bruteForceStrategy[lockedColumn]++;
		}
		return lockedColumn;
	};
	int depthMissing(F field, int column, int row) {
		int counter = 0;
		for (row; row < F::height; row++) {
			if (field.rep[column][row] == F::none) {
				counter++;
			}
			else {
				return counter;
			}
		}
		return counter;

	}

public:
	player(bool ai, int i) : AI(ai), ID(i) {};
	// returns the column where the player decides to insert his
	// stone
	// F is the playfield which may be any playfield implementing
	// the stoneat method, if you expect a different class because
	// you need methods to verify whether the opponent can win,
	// copy the field into the class that you expect.
	int play(const F& field) {
		if (AI) {
			std::cout << "computer played" << std::endl;
			return AILogic(field);
		}
		else {
			bool choosing = true;
			int column;

			while (choosing) {
				std::cout << "Please choose a column from 1 to " << field.width << std::endl;
				std::cin >> column;
				if (column - 1 < field.width && field.stoneat(column - 1, 0) == field.none) {
					choosing = false;
					return column - 1;
				}
				else {
					std::cout << "Chosen column does either not exist or is already full" << std::endl;
				}
			}
		}
	}

};
