#include <iostream>
// #include "Equation.h"
#include "../include/Equation.h"
#include <vector>

// void compute()

// Equation::Equation() {
//     // Constructor implementation (even if empty)
// }

std::vector<float> Equation::compute(IMesh * mshptr) const{
    int n_i = mshptr->nb_point; 
    std::vector<float> u(n_i, 0);
    
    
    


    for (int i =1 ; i<= n_i-1 ; i++ ){/*we take exclude index 0 and n as they are the boundary condition*/

        std::cout <<"-- at x_i = "<< i <<"\n";
        // u[i][k+1] = (u[i-1][k] + u[i+1][k] )/2 ; 
        u[i] = (u[i-1] + u[i+1] )/2 ; 

    }

    return u ; 
}


// int main(){
//     return 0; 
// }