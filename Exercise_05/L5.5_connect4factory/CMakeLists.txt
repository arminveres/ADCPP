cmake_minimum_required(VERSION 3.1)
project(L5.4_connect4inheritance)

set(CMAKE_CXX_STANDARD 17)

add_executable(connect4 
    main.cpp 
    human_player.cpp
    comp_player.cpp
    my_playfield.cpp
    player_factory.cpp
)
