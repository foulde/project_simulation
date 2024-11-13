#ifndef PROBLEM_H
#define PROBLEM_H

#include"Equation.h"

#include <vector>

class Problem{


public: 

// Problem(Equation eq , IMesh* mshptr /*we define a mesh pointer that will be called by the compute */ );
// Problem(const Equation& eq, IMesh* mshptr); // Constructor
public:
Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

~Problem();

    // std::vector<float> solve(Equation eq); 
    std::vector<float> solve(const Equation& eq , int nb_iter) const; 
    


private:
    Equation equation_;  // Store the equation 
    IMesh* mesh_ptr_;    // Mesh pointer member

}; 



#endif