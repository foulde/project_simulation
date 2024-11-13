#include<iostream>
// #include "Equation.h"
#include "../include/Equation.h"

#include "Problem.h"


int main(){

// struct UniformMesh : public IMesh{
//     float x_min_=0; 
//     float x_max_= 1;
//     int nb_point_ =8; 
//     float dx(int); 
//     float m_dx_=0.2; 
//     UniformMesh(float x_min , float x_max , int nb_point ) : x_min_(x_min) ,x_max_(x_max) , nb_point_(nb_point){} 
//     // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

//     ~UniformMesh();

// };


    Equation e ;
    UniformMesh u(0 ,5 , 10); 
    u.print(); 
    std::cout << "tu es dans le main" << "\n";

    


    return 0; 
}