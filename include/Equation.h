#include<stdlib.h>
#include<vector>
#include<iostream>
#include <functional> // Include this for std::function

#include"IMesh.h"
#include"Variable.h"
#ifndef EQUATION_H
#define EQUATION_H


// define function for equation





// struct IMesh{
// virtual ~IMesh() = default;


// double x_min_=0; 
// double x_max_= 1;
// int nb_point_ =8; 
// double dx(int); 
// double m_dx_=0.2; 
// // int x_size();
// virtual int x_size() ;
// double x_i(int i ); 




// }; 

// struct UniformMesh : public IMesh{
//     double x_min_=0; 
//     double x_max_= 1;
//     int nb_point_ =8; 
//     double dx(int); 
//     double m_dx_=abs(x_max_-x_min_)/nb_point_; 
//     public:

//     UniformMesh(double x_min , double x_max , int nb_point ) : x_min_(x_min) ,x_max_(x_max) , nb_point_(nb_point){} 
//     // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

//     // ~UniformMesh();
//     int x_size()  override { 
//         return nb_point_;
//     }

//     // double x_i(int i ); 


    
//     void print(){std::cout<< "the element of the class are : "<< "\n-x_min= "<<x_min_
//                                                               << "\n-x_max= "<<x_max_
//                                                               << "\n-nb_point= "<<nb_point_
//                                                               <<"\n"; 

//     }

// };

// struct NonUniformMesh : public IMesh{
//     double x_min=0; 
//     double x_max= 1;
//     int nb_point =8; 
//     double dx(int); 
//     std::vector<double> spaces ; 

// };




struct Equation{



public:
    // Equation(); 
    virtual ~Equation() = default;
    // std::vector<double> compute(IMesh * mshptr ,  Variable &u_k ,Variable &u_kp1) const; /*this is the compute function that will be called in problem */
    void compute(IMesh * mshptr ,  Variable &u_k ,Variable &u_kp1) const; /*this is the compute function that will be called in problem */
    
    void compute_exact_solution(Variable &u_ref ,IMesh * mshptr )const;
    // compute_initial_condition
    void compute_initial_condition( Variable &Variable ,  IMesh *mshptr )const; 
    void compute_initial_condition_lambda( Variable &Variable ,  IMesh *mshptr ,std::function<double(double)> initial_condition )const; 
    void compute_boundary_conditions(Variable &Variable , IMesh *meshpt )const; 

    // template<Method>
    // void compute_for_scheme(IMesh *mshptr , Variable &u_k ,Variable &u_kp1);


    // template<class Method>
    // void compute_for_solver(IMesh *mshptr , Variable &u_k ,Variable &u_kp1)const;


    template<class Method>
    void compute_for_solver(IMesh *mshptr , Variable &u_k ,Variable &u_kp1)const{
    int n_i = mshptr->nb_point_;     
    std::cout <<"-- at n_i = "<< n_i <<"\n\n";
    Method::compute_iteration(mshptr , u_k ,u_kp1);
}


}; 






#endif