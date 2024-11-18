#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include<iostream>
#include"IMesh.h"
#include"Variable.h"
#include"UniformMesh.h"

struct GaussSeidel{
    static void compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1) ;
};

#endif