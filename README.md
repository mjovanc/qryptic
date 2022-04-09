# blockchain-cpp
Simple Blockchain written in C++ for learning purposes. 

## Setup and run

1. Clone the repository
2. Run `cmake .` to initialize CMake project
3. Run `cmake -B ./build -S .`
4. Go to build directory and run `make`
5. Run executable `./BlockchainCPP`

## Output

The output when running the application:

```
Mining block 1...
Block mined: 0000006ee9287cdbdf3db023f75184f8b4a03335e4616dce8115467c4a388c0b
Mining block 2...
Block mined: 0000008b49647809ec537284d4853152e49b7a1757a5b1af4449a89b5151fa4b
Mining block 3...
Block mined: 000000f0afe28da43bc218c23a5d6ecbbc3b7e7efa80db61c7bfc5302759256c
```

## Unit tests

To run the test cases in **blockchain_test.cpp** that comes along we need (after we have built) to run:

`./build/blockchain_test`

We need in the future to link all test files so we can run all unit tests at once.

## Clean 

If we want to do a cleanup of generated files during build we can run:

`git clean -xfd`
