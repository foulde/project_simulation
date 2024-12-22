#include<iostream>
#include<vector>
#include"../include/Problem.h"
#include"../include/Equation.h"
#include "../include/UniformMesh.h"
#include "../include/Timer.h"


int main(){


  
    Equation e ;
    double x_min =0 ; 
    double x_max =1 ; 
    // int nb_points = 50000;
    int nbiteration = 100;
 

    double dx =1e-6; 

    // UniformMesh u(0 ,5 , 10); /*calling */
    // UniformMesh u(x_min ,x_max , nb_points); /*calling */
    UniformMesh u(x_min ,x_max , dx); /*calling */
    u.print();
    // std::vector<double> toto = e.compute(&u) ; 
    std::cout << "tu es dans le main" << "\n";
    
    // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}
    Problem p1(e, &u); 
    // std::vector<double> toto = p1.solve(10); 
    // p1.solve(1000); 
    // p1.solve(1000 , "Jacobi"); 

    // p1.solve(1000 , "GaussSeidel");


    std::cout<<"\n\nthis is parrallel Jacobi\n\n"; 
    Timer c ; 
    c.tstart() ;
    // p1.solve(100 , "GaussSeidel"); 
    p1.solve_parallel(nbiteration , "Jacobi"); 
    c.tstop();

    c.print();


    std::cout<<"\n\nthis is sequential Jacobi \n\n"; 
    Timer b ; 
    b.tstart() ;
    // p1.solve(100 , "GaussSeidel"); 
    p1.solve(nbiteration , "Jacobi"); 
    b.tstop();

    b.print();


    std::cout<<"\n\nthis is sequential Gaussiedel\n\n"; 

    Timer a ; 
    a.tstart() ;
    // p1.solve(100 , "GaussSeidel"); 
    p1.solve(nbiteration , "GaussSeidel"); 
    a.tstop();

    a.print();








    


    return 0; 
}