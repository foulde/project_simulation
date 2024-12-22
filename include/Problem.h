#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>
#include <algorithm>
#include <execution>


#include"Equation.h"
#include"IMesh.h"
#include"Variable.h"



struct Problem{



public:
Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}


    void solve( int nb_iter) const; 
    void solve(int nb_iter , std::string method) const; 
    void solve_parallel(int nb_iter , std::string method) const; 


    bool has_converged( const Variable &u_k ,const Variable &u_kp1 )const; /*te parameter are const as 
                                                                            we do not modify them*/
    


private:
    Equation equation_;  // Store the equation 
    IMesh* mesh_ptr_;    // Mesh pointer member

}; 



#endif