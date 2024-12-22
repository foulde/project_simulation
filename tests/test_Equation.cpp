#include <iostream>
#include <cassert>
#include <vector>
#include "../include/Equation.h"
#include "../include/UniformMesh.h"
#include "../include/Variable.h"

// Test compute_boundary_conditions
void test_compute_boundary_conditions() {
    UniformMesh mesh(0, 10, 5); 
    Variable variable(&mesh);  
    Equation equation;

    equation.compute_boundary_conditions(variable, &mesh);

    assert(variable[0] == 30); // Boundary condition T1
    assert(variable[4] == 15); // Boundary condition T2
    std::cout << "test_compute_boundary_conditions passed!" << std::endl;
}

/*Test for compute_initial_condition*/
void test_compute_initial_condition() {
    UniformMesh mesh(0, 10, 10); 
    Variable variable(&mesh);    
    Equation equation;

    equation.compute_initial_condition(variable, &mesh);

    for (int i = 0; i < 5; i++) {
        assert(variable[i] == 30); // T1
    }
    for (int i = 5; i < 10; i++) {
        assert(variable[i] == 15); // T2
    }
    std::cout << "test_compute_initial_condition passed!" << std::endl;
}

// Test for compute_initial_condition_lambda
void test_compute_initial_condition_lambda() {
    UniformMesh mesh(0, 10, 5); 
    Variable variable(&mesh);   
    Equation equation;

    // Lambda: Ti = x_i * 2
    auto lambda = [](double x) { return x * 2; };

    equation.compute_initial_condition_lambda(variable, &mesh, lambda);

    for (int i = 0; i < 5; i++) {
        double expected_value = mesh.x_i(i) * 2;
        assert(variable[i] == expected_value);
    }
    std::cout << "test_compute_initial_condition_lambda passed!" << std::endl;
}

// Test for compute_exact_solution
void test_compute_exact_solution() {
    UniformMesh mesh(0, 10, 5); // 5 points from 0 to 10
    Variable u_ref(&mesh);      // Correct initialization of Variable
    Equation equation;

    equation.compute_exact_solution(u_ref, &mesh);

    assert(u_ref[0] == 30);        // T1 at start
    assert(u_ref[4] == 15);        // T2 at end
    for (int i = 1; i < 4; i++) {  
        double xi = mesh.x_i(i);
        double expected_value = ((15 - 30) / 10.0) * xi + 30;
        assert(u_ref[i] == expected_value);
    }
    std::cout << "test_compute_exact_solution passed!" << std::endl;
}

// Test for compute 
void test_compute() {
    UniformMesh mesh(0, 10, 5); 
    Variable u_k(&mesh);        
    Variable u_kp1(&mesh);      
    Equation equation;

    // Set initial values for u_k
    for (int i = 0; i < mesh.x_size(); i++) {

        u_k[i] = i * 1.0; // Example values: 0, 1, 2, 3, 4
    }



    equation.compute(&mesh, u_k, u_kp1);


    for (int j = 1; j < 4; j++) {  // Values at interior points
        double expected_value = (u_k[j - 1] + u_k[j + 1]) / 2.0;
        assert(u_kp1[j] == expected_value);
    }
    std::cout << "test_compute passed!" << std::endl;
}

int main() {

    Equation e ;

    UniformMesh u(0 ,5 , 10); 
    u.print();
    // std::vector<double> toto = e.compute(&u) ; 
    std::cout << "tu es dans le main" << "\n";

    test_compute_boundary_conditions();
    test_compute_initial_condition();
    test_compute_initial_condition_lambda();
    test_compute_exact_solution();
    test_compute();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}




