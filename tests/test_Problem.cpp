#include<iostream>
#include<vector>
#include"../include/Problem.h"
#include"../include/Equation.h"
#include "../include/UniformMesh.h"


int main(){

// struct UniformMesh : public IMesh{
//     double x_min_=0; 
//     double x_max_= 1;
//     int nb_point_ =8; 
//     double dx(int); 
//     double m_dx_=0.2; 
//     UniformMesh(double x_min , double x_max , int nb_point ) : x_min_(x_min) ,x_max_(x_max) , nb_point_(nb_point){} 
//     // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

//     ~UniformMesh();

// };


    // Equation e ;
    // UniformMesh u(0 ,5 , 10); 
    // u.print(); 
    // std::cout << "tu es dans le main" << "\n";

    Equation e ;
    double x_min =0 ; 
    double x_max =1 ; 
    int nb_points = 100;
    // double dx =0.01; 
    // double dx =0.01; 
    // double dx =1e-6; 
    double dx =1e-6; 

    // UniformMesh u(0 ,5 , 10); /*calling */
    UniformMesh u(x_min ,x_max , nb_points); /*calling */
    // UniformMesh u(x_min ,x_max , dx); /*calling */
    u.print();
    // std::vector<double> toto = e.compute(&u) ; 
    std::cout << "tu es dans le main" << "\n";
    
    // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}
    Problem p1(e, &u); 
    // std::vector<double> toto = p1.solve(10); 
    // p1.solve(1000); 
    // p1.solve(1000 , "Jacobi"); 
    // p1.solve(1000 , "GaussSeidel"); 
    p1.solve(100 , "GaussSeidel"); 



    


    return 0; 
}