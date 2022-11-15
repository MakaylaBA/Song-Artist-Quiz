cmake_minimum_required(VERSION 3.21)
project(Song_Artist)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Song_Artist main.cpp Song.cpp Artist.cpp MusicLabel.cpp
                    Quiz.cpp Question.cpp)
add_executable(test testing.cpp Song.cpp Artist.cpp MusicLabel.cpp
                    Question.cpp Quiz.cpp)
