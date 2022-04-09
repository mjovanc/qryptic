cmake_minimum_required(VERSION 3.10)

# set the project name
project(BlockchainCPP)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# add the subdirectories
add_subdirectory(chain)
add_subdirectory(crypto)

# include directories
target_include_directories(${PROJECT_NAME} PUBLIC chain crypto)

# link libraries
target_link_directories(${PROJECT_NAME} PRIVATE chain crypto)
target_link_libraries(${PROJECT_NAME} chain crypto)