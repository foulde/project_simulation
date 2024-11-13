
#include "../include/Problem.h"
#include "../include/Equation.h"
#include <iostream>



//contient un membre de type equation ---> equation est peut être une classe 


std::vector<float> Problem::solve(const Equation& eq , int nb_iter) const{
    
    // nbiter = mesh_ptr_.nb

    // int n_i = mshptr->nb_point; 
    // std::vector<float> solution( mesh_ptr->nb_point, 0);
    std::vector<float> solution( mesh_ptr_->nb_point, 0);
    
    // std::vector<float> solution  ; 

    
    for( int k =1 ; k <=nb_iter  ; k++){
        std::cout<<"--- Iterative methode iteration : "<<k<<" ---\n";
        // solution  = eq.compute(mesh_ptr); 
        solution  = eq.compute(mesh_ptr_); 
        // compute 

    }
    return solution;


}




// int main(){
//     // UniformMesh
//     UniformMesh stmesh; 

    
//     return 0; 
// }
