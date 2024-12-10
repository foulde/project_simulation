
cmake_minimum_required(VERSION 3.10)

project(PROJECT_SIMULATION)

set(CMAKE_CXX_STANDARD 17)


include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable target and source files
# add_executable(SimulatorProject src/main.cpp src/Problem.cpp src/Equation.cpp)
add_executable(SimulatorProject src/main.cpp
            src/Problem.cpp 
            src/Equation.cpp
            src/UniformMesh.cpp
            src/Variable.cpp  
            src/Jacobi.cpp  
            src/GaussSeidel.cpp
            include/Equation.h 
            include/Problem.h
            include/IMesh.h
            include/UniformMesh.h
            include/Variable.h
            include/Jacobi.h
            include/GaussSeidel.h
            )


            


# add_executable(SimulatorProject
#     src/main.cpp
#     src/Problem.cpp
#     src/Equation.cpp  # Make sure this is included
# )


# add_library(test_Problem src/Problem.cpp)


#testing

enable_testing()


# Add tests
# add_executable(test_Problem tests/test_Problem.cpp src/Problem.cpp src/Equation.cpp src/UniformMesh.cpp)
# add_executable(test_Equation tests/test_Equation.cpp src/Equation.cpp  src/UniformMesh.cpp)

add_executable(test_Problem tests/test_Problem.cpp 
               src/Problem.cpp src/Equation.cpp
                src/UniformMesh.cpp src/Variable.cpp
                src/Jacobi.cpp 
                src/GaussSeidel.cpp )

                # Add a debug flag based on the build type
#will build test_Problem with the print else will not show the print output .

#To get the debug mode must be called with :
#cmake -DCMAKE_BUILD_TYPE=Debug ..

# go to buildrelease folder and run 
#cmake -D CMAKE_BUILD_TYPE=Release ..


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
target_compile_definitions(test_Problem PRIVATE DEBUG)
endif()





add_executable(test_Equation tests/test_Equation.cpp 
                src/Equation.cpp
                src/UniformMesh.cpp
                src/Variable.cpp
                src/Jacobi.cpp 
                src/GaussSeidel.cpp)


# Add tests to CTest
add_test(NAME TestProblem COMMAND test_Problem)
add_test(NAME TestEquation COMMAND test_Equation)

