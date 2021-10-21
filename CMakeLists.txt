cmake_minimum_required(VERSION 3.20)
project(ADCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw Exercise_01/L1.1_helloWorld.cpp)
add_executable(txt Exercise_01/L1.1_txtConverter.cpp)
add_executable(frac Exercise_01/L1.2_fraction.cpp)
add_executable(spellCheck Exercise_01/L1.3_simpleSpellChecker.cpp)
add_executable(revPol Exercise_01/L1.4_revPolCalc.cpp)
add_executable(pvector Exercise_02/pvector.cpp Exercise_02/pvector.h Exercise_02/fraction.cpp Exercise_02/fraction.h)
add_executable(revPolTemp Exercise_02/revPolTemplate.cpp)
