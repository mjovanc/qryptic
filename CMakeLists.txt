cmake_minimum_required(VERSION 3.10)

# set the project name
project(BlockchainCPP)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(Blockchain main.cpp Blockchain.cpp Block.cpp sha256.cpp)