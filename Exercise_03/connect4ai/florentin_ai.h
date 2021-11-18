
// This is adapted from the python implementation here:
// https://github.com/KeithGalli/Connect4-Python
// The score heuristic is from a different internet source (missing url, unfortunately)

#ifndef player_cpu_hpp
#define player_cpu_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct mmResult {
    int score = 0;
    int col = 0;
};

template<typename F>
struct player_cpu {

    int id;
    

    // returns the column where the player decides to insert his
    // stone
    // F is the playfield which may be any playfield implementing
    // the stoneat method, if you expect a different class because
    // you need methods to verify whether the opponent can win,
    // copy the field into the class that you expect.
    int play(const F &field)
    {
        if (m_isFirstMove)
        {
            m_isFirstMove = false;
            for (int row=0; row<field.height; ++row)
            {
                for (int col=0; col<field.width; ++col)
                {
                    if (field.stoneat(col, row) != 0)
                    {
                        m_myColor = 2;
                        m_oppColor = 1;
                    }
                }
            }
        }
        
        mmResult res = miniMax(field, 6, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), true);
        cout << res.col << " (" << res.score << ")" << endl;
        return res.col;
    }
    
    mmResult miniMax(const F& field, int depth, int alpha, int beta, bool maximizingPlayer)
    {
        mmResult ret;
        
        vector<pair<int, int>> validLocations = GetValidLocations(field);
        
        if (CheckWinner(m_oppColor, field))
        {
            ret.score = std::numeric_limits<int>::min();
            return ret;
        }
        if (CheckWinner(m_myColor, field))
        {
            ret.score = std::numeric_limits<int>::max();
            return ret;
        }
        if (validLocations.size() == 0) return ret;
        if (depth == 0)
        {
            ret.score = ComputeScore(field, maximizingPlayer ? m_myColor : m_oppColor);
            return ret;
        }
        if (maximizingPlayer)
        {
            int randIdx = rand() % validLocations.size();
            int column = validLocations[randIdx].first;
            int value = std::numeric_limits<int>::min();
            for (int i=0; i<validLocations.size(); ++i)
            {
                int col = validLocations[i].first;
                
                F fieldCopy = field;
                fieldCopy.rep[col][validLocations[i].second] = m_myColor;
                
                int newScore = miniMax(fieldCopy, depth-1, alpha, beta, false).score;
                
                if (newScore > value)
                {
                    value = newScore;
                    column = col;
                }
                alpha = max(alpha, value);
                if (alpha >= beta) break;
            }
            ret.col = column;
            ret.score = value;
            return ret;
        }
        else
        {
            int randIdx = rand() % validLocations.size();
            int column = validLocations[randIdx].first;
            int value = std::numeric_limits<int>::max();
            for (int i=0; i<validLocations.size(); ++i)
            {
                int col = validLocations[i].first;
                
                F fieldCopy = field;
                fieldCopy.rep[col][validLocations[i].second] = m_oppColor;
                
                int newScore = miniMax(fieldCopy, depth-1, alpha, beta, true).score;
                if (newScore < value)
                {
                    value = newScore;
                    column = col;
                }
                beta = min(beta, value);
                if (alpha >= beta) break;
            }
            ret.col = column;
            ret.score = value;
            return ret;
        }
        return ret;
    }
    
    vector<pair<int, int>> GetValidLocations(const F& field)
    {
        vector<pair<int, int>> ret;
        for (int col=0; col<field.width; ++col)
        {
            int row = GetFreeRow(col, field);
            if (row > -1) ret.push_back({col, row});
        }
        return ret;
    }
    
    int GetFreeRow(int col, const F& field)
    {
        for (int row=field.height-1; row>=0; --row)
        {
            if (field.stoneat(col, row) == 0)
            {
                return row;
            }
        }
        return -1;
    }
    
    // Checks if the last stone won
    bool CheckWinner(const int& player, const F& field)
    {
        if (CheckHor(player, field) || CheckVer(player, field) || CheckDia1(player, field) || CheckDia2(player, field))
        {
            return true;
        }
        return false;
    }
    
    // Checks for horizontal win
    bool CheckHor(const int& player, const F& field)
    {
        for (int row=0; row<field.height; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count = 0;
                for (int i=0; i<4; ++i)
                {
                    if (field.stoneat(col+i, row) == player) count++;
                }
                if (count == 4) return true;
            }
        }
        return false;
    }
    
    // Checks for vertical win
    bool CheckVer(const int& player, const F& field)
    {
        for (int col=0; col<field.width; ++col)
        {
            for (int row=0; row<field.height - 3; ++row)
            {
                int count = 0;
                for (int i=0; i<4; ++i)
                {
                    if (field.stoneat(col, row+i) == player) count++;
                }
                if (count == 4) return true;
            }
        }
        return false;
    }
    
    bool CheckDia1(const int& player, const F& field)
    {
        for (int row=0; row<field.height - 3; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count = 0;
                for (int i=0; i<4; ++i)
                {
                    if (field.stoneat(col+i, row+i) == player) count++;
                }
                if (count == 4) return true;
            }
        }
        return false;
    }
    
    bool CheckDia2(const int& player, const F& field)
    {
        for (int row=0; row<field.height - 3; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count = 0;
                for (int i=0; i<4; ++i)
                {
                    if (field.stoneat(col+i, row+3-i) == player) count++;
                }
                if (count == 4) return true;
            }
        }
        return false;
    }
    
    int ComputeScore(const F& field, const int& player)
    {
        int score = 0;
        
        // Score horizontal
        score += ScoreHorizontal(field, player);
        
        // Score vertical
        score += ScoreVertical(field, player);
        
        // Score diagonal 1
        score += ScoreDiagonal1(field, player);
        
        // Score diagonal 2
        score += ScoreDiagonal2(field, player);
        
        return score;
    }
    
    int ScoreHorizontal(const F& field, const int& player)
    {
        int score = 0;
        for (int row=0; row<field.height; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count[3] = {0, 0, 0};
                count[field.stoneat(col, row)]++;
                count[field.stoneat(col + 1, row)]++;
                count[field.stoneat(col + 2, row)]++;
                count[field.stoneat(col + 3, row)]++;
                score += EvaluateWindow(count, player);
            }
        }
        return score;
    }
    
    int ScoreVertical(const F& field, const int& player)
    {
        int score = 0;
        for (int col=0; col<field.width; ++col)
        {
            for (int row=0; row<field.height - 3; ++row)
            {
                int count[3] = {0, 0, 0};
                count[field.stoneat(col, row)]++;
                count[field.stoneat(col, row + 1)]++;
                count[field.stoneat(col, row + 2)]++;
                count[field.stoneat(col, row + 3)]++;
                score += EvaluateWindow(count, player);
            }
        }
        return score;
    }
    
    int ScoreDiagonal1(const F& field, const int& player)
    {
        int score = 0;
        for (int row=0; row<field.height - 3; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count[3] = {0, 0, 0};
                count[field.stoneat(col, row)]++;
                count[field.stoneat(col + 1, row + 1)]++;
                count[field.stoneat(col + 2, row + 2)]++;
                count[field.stoneat(col + 3, row + 3)]++;
                score += EvaluateWindow(count, player);
            }
        }
        return score;
    }
    
    int ScoreDiagonal2(const F& field, const int& player)
    {
        int score = 0;
        for (int row=0; row<field.height - 3; ++row)
        {
            for (int col=0; col<field.width - 3; ++col)
            {
                int count[3] = {0, 0, 0};
                count[field.stoneat(col, row + 3)]++;
                count[field.stoneat(col + 1, row + 2)]++;
                count[field.stoneat(col + 2, row + 1)]++;
                count[field.stoneat(col + 3, row)]++;
                score += EvaluateWindow(count, player);
            }
        }
        return score;
    }
    
    int EvaluateWindow(const int count[3], const int& player)
    {
        int opp = 1;
        if (player == 1) opp = 2;
        int score = 0;
        
        if (count[player] == 3 && count[0] == 1) score += 5000;
        else if (count[player] == 2 && count[0] == 2) score += 500;
        else if (count[opp] == 2 && count[0] == 2) score -= 501;
        else if (count[opp] == 3 && count[0] == 1) score -= 5001;
        
        return score;
    }
    
    bool m_isFirstMove = true;
    int m_myColor = 1;
    int m_oppColor = 2;
};

#endif /* player_cpu_hpp */
