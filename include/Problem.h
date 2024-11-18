#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include"Equation.h"
#include"IMesh.h"
#include"Variable.h"


class Problem{


public: 

// Problem(Equation eq , IMesh* mshptr /*we define a mesh pointer that will be called by the compute */ );
// Problem(const Equation& eq, IMesh* mshptr); // Constructor
public:
Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

// ~Problem();
// ~Problem() { delete mesh_ptr_; }


    // std::vector<double> solve(Equation eq); 
    // std::vector<double> solve( int nb_iter) const; 
    void solve( int nb_iter) const; 
    bool has_converged( const Variable &u_k ,const Variable &u_kp1 )const; /*te parameter are const as 
                                                                            we do not modify them*/
    


private:
    Equation equation_;  // Store the equation 
    IMesh* mesh_ptr_;    // Mesh pointer member

}; 



#endif