cmake_minimum_required(VERSION 3.10)

# set the project name
project(BlockchainCPP)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  blockchain_test
  ./test/blockchain_test.cpp
)

include(GoogleTest)
gtest_discover_tests(blockchain_test)
target_link_libraries(blockchain_test gtest_main)

# directories to be included
include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.cpp)


# add the subdirectories
add_subdirectory(chain)
add_subdirectory(crypto)

# include directories
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  chain
  crypto
  wallet
)

# link libraries
target_link_directories(
  ${PROJECT_NAME}
  PRIVATE
  chain
  crypto
  wallet
)
target_link_libraries(
  ${PROJECT_NAME}
  chain
  crypto
  wallet
)