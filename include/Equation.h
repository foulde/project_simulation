#include<stdlib.h>
#include<vector>
#include<iostream>
#ifndef EQUATION_H
#define EQUATION_H


// define function for equation





struct IMesh{
virtual ~IMesh() = default;


float x_min=0; 
float x_max= 1;
int nb_point =8; 
float dx(int); 


}; 

struct UniformMesh : public IMesh{
    float x_min_=0; 
    float x_max_= 1;
    int nb_point_ =8; 
    float dx(int); 
    float m_dx_=0.2; 
    public:

    UniformMesh(float x_min , float x_max , int nb_point ) : x_min_(x_min) ,x_max_(x_max) , nb_point_(nb_point){} 
    // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

    // ~UniformMesh();
    
    void print(){std::cout<< "the element of the class are : "<< "\n-x_min= "<<x_min_
                                                              << "\n-x_max= "<<x_max_
                                                              << "\n-nb_point= "<<nb_point_
                                                              <<"\n"; 

    }

};

struct NonUniformMesh : public IMesh{
    float x_min=0; 
    float x_max= 1;
    int nb_point =8; 
    float dx(int); 
    std::vector<float> spaces ; 

};




struct Equation{



public:
    // Equation(); 
    virtual ~Equation() = default;
    std::vector<float> compute(IMesh * mshptr) const; /*this is the compute function that will be called in problem */
    
}; 




#endif