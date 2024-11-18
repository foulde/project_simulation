#ifndef JACOBI_H
#define JACOBI_H

#include<iostream>
#include"IMesh.h"
#include"Variable.h"
#include"UniformMesh.h"

struct Jacobi{
    static void compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1) ;
};

#endif