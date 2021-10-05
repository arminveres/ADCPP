cmake_minimum_required(VERSION 3.20)
project(ADCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw Exercise_01/helloWorld.cpp)
add_executable(txt Exercise_01/txtConverter.cpp)
add_executable(frac Exercise_01/fraction.cpp Exercise_01/revPolCalc.cpp)
add_executable(spellCheck Exercise_01/simpleSpellChecker.cpp)
add_executable(revPol Exercise_01/revPolCalc.cpp)
