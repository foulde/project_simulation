#ifndef IMESH_H
#define IMESH_H
#include<stdlib.h>
#include<vector>
#include<iostream>
#include <execution>
#include <algorithm>



struct IMesh{
// virtual ~IMesh() = default;

virtual ~IMesh() = default;  // Virtual destructor to enable proper cleanup

double x_min_=0; 
double x_max_= 1;
int nb_point_ =8; 
// double dx(int)=0; 
double m_dx_=0.2; 
// int x_size();
// virtual int x_size() ;

virtual int x_size()  = 0;    // Pure virtual function for x_size
// virtual double x_i(int i )=0 ; 
virtual double x_i(int i) = 0;


}; 




#endif