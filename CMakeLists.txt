cmake_minimum_required(VERSION 3.20)
project(ADCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw
        Exercise_01/L1.1_helloWorld.cpp)

add_executable(txt
        Exercise_01/L1.1_txtConverter.cpp)

add_executable(frac
        Exercise_01/L1.2_fraction.cpp)

add_executable(spellCheck
        Exercise_01/L1.3_simpleSpellChecker.cpp)

add_executable(revPol
        Exercise_01/L1.4_revPolCalc.cpp)

add_executable(pvector1
        Exercise_02/pvector.cpp
        Exercise_02/pvector.h
        Exercise_02/fraction.cpp
        Exercise_02/fraction.h)

add_executable(revPolTemp
        Exercise_02/fraction.cpp
        Exercise_02/revPolTemplate.cpp)

add_executable(pvector2
        Exercise_03/pVector/pvector.h
        Exercise_03/pVector/main.cpp
        Exercise_03/pVector/persistance_traits.h
        Exercise_03/pVector/pset.h)

add_executable(dumbPointer
        Exercise_03/pointer_emulation/dumb_pointer.h
        Exercise_03/pointer_emulation/main.cpp
        Exercise_03/pointer_emulation/smart_pointer.h)

add_executable(rpn3
        Exercise_03/revPolCalcComplex/main.cpp
        Exercise_03/revPolCalcComplex/rpn.h
        Exercise_03/revPolCalcComplex/minmax_traits.h
        Exercise_02/fraction.cpp
        Exercise_02/fraction.h)

add_executable(spellchecker2
        Exercise_03/SpellChecker/simplespellchecker.cpp
        Exercise_03/SpellChecker/simplespellchecker.h
        Exercise_03/SpellChecker/main.cpp
        Exercise_03/pVector/pset.h)

add_executable(connect4
        Exercise_03/connect4ai/playfield.cpp
        Exercise_03/connect4ai/playfield.h Exercise_03/connect4ai/playfield_traits.h Exercise_03/connect4ai/game.h Exercise_03/connect4ai/main.cpp Exercise_03/connect4ai/human_player.h Exercise_03/connect4ai/comp_player.h)
