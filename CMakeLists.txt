
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
            include/Equation.h 
            include/Problem.h
            include/IMesh.h
            include/UniformMesh.h
            include/Variable.h
            include/Jacobi.h
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
                src/Jacobi.cpp  )
add_executable(test_Equation tests/test_Equation.cpp src/Equation.cpp src/UniformMesh.cpp src/Variable.cpp)


# Add tests to CTest
add_test(NAME TestProblem COMMAND test_Problem)
add_test(NAME TestEquation COMMAND test_Equation)

