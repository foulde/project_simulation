# Problem Solver Project

This project attempt to solve numerically the 1D steady state heat equation
using iterative method like Jacobi and GaussSeidel.

## Build and Test Instructions

# 1. Create and navigate to the build directory:

    mkdir buildrelease
    cd buildrelease

# 2. Run CMake to generate build files:
    bash
    cmake ..
    

# 3. Compile the project:
    bash
    make
    

# 4. Run unit tests with CTest:
    bash
    ctest
    

# 5. Execute the test binary directly (optional):
    bash
    ./test_Problem
    

# ## Project Structure

 - **`Problem.h` / `Problem.cpp`**: Implementation of the problem solver.
 - **`test_Problem.cpp`**: Unit tests for the problem solver.
 - **`CMakeLists.txt`**: CMake configuration file for building the project.
