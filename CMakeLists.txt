cmake_minimum_required(VERSION 3.15)
project(Chess)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -pedantic-errors -g")

include_directories(include)

set(SOURCE_FILES
        src/Bishop.cpp
        src/Board.cpp
        src/King.cpp
        src/Knight.cpp
        src/Location.cpp
        src/main.cpp
        src/Pawn.cpp
        src/Queen.cpp
        src/Reactor.cpp
        src/Rook.cpp)

add_executable(Chess ${SOURCE_FILES})
