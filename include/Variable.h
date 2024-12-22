#ifndef VARIABLE_H
#define VARIABLE_H

#include<iostream>
#include<vector>
#include <algorithm>
#include <execution>
#include <string>

#include"IMesh.h"



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


    /* STL compatibility with for each */
    auto begin() { return u.begin(); }
    auto end() { return u.end(); }
    auto begin() const { return u.begin(); }
    auto end() const { return u.end(); }

    

    double max_element() const; 

    void print(std::string name ); 
    void printvtk(std::string name );


} ;





#endif