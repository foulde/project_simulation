#ifndef UNIFORM_MESH_H
#define UNIFORM_MESH_H

#include<stdlib.h>
#include<vector>
#include<iostream>
#include <cmath>
#include <algorithm>
#include <execution>


#include"IMesh.h"



struct UniformMesh : public IMesh{
    // double x_min_=0; 
    // double x_max_= 1;
    // int nb_point_ =8; 
    // // double dx(int); 
    // double m_dx_=abs(x_max_-x_min_)/(nb_point_-1); 

    // UniformMesh(double x_min , double x_max , int nb_point ) : x_min_(x_min) ,x_max_(x_max) , nb_point_(nb_point){} 
    public: 

    UniformMesh(double x_min, double x_max, int nb_point) {
        x_min_ = x_min;
        x_max_ = x_max;
        nb_point_ = nb_point;
        m_dx_ = std::abs(x_max - x_min) / (nb_point - 1);
    }

    UniformMesh(double x_min, double x_max, double dx) {
        x_min_ = x_min;
        x_max_ = x_max;
        m_dx_ =dx; 

        nb_point_ = std::floor(abs(x_max -x_min) /dx)+1;
        // m_dx_ = std::abs(x_max - x_min) / (nb_point - 1);
    }



    // Problem(const Equation& eq, IMesh* mesh_ptr) : equation_(eq), mesh_ptr_(mesh_ptr) {}

    // ~UniformMesh();
    int x_size()  override ;
    double x_i(int i ) override; 

    // double x_i(int i ); 


    
    void print(){std::cout<< "the element of the class are : "<< "\n-x_min= "<<x_min_
                                                              << "\n-x_max= "<<x_max_
                                                              << "\n-nb_point= "<<nb_point_
                                                              << "\n-m_dx_= "<<m_dx_
                                                              <<"\n"; 

    }

};




#endif