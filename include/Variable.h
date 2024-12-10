#ifndef VARIABLE_H
#define VARIABLE_H

#include<iostream>
#include<vector>
#include"IMesh.h"
#include <string>



struct Variable{

// private : 
public  : 
    IMesh* mesh_ptr_; 
    std::vector<double> u; 
public : 
    Variable(IMesh* mesh_ptr):
    mesh_ptr_(mesh_ptr) ,u(mesh_ptr_->x_size() , 0){}

    double& operator[](int); 
    const double& operator[](int) const;
    

    double max_element() const; 

    void print(std::string name ); 
    void printvtk(std::string name );


} ;





#endif