cmake_minimum_required(VERSION 3.15)
project(game_tester)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_tester main.cpp Scenario.cpp Scenario.hpp Spell.cpp Spell.hpp
        Transcript.cpp Transcript.hpp)