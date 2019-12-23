cmake_minimum_required(VERSION 3.9)
project(Chess)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -g")

include_directories("./include")

set(SOURCE_FILES
        ./src/Bishop.cpp
        ./src/King.cpp
        ./src/Knight.cpp
        ./src/Pawn.cpp
        ./src/Queen.cpp
        ./src/Rook.cpp
        )
add_executable(Chess ${SOURCE_FILES})
