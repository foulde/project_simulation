#ifndef JACOBI_H
#define JACOBI_H

#include<iostream>
#include <algorithm>
#include <algorithm>
#include <execution>



#include"IMesh.h"
#include"Variable.h"
#include"UniformMesh.h"


struct Jacobi{
    static void compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1) ;
    static void compute_iteration_parrallel(IMesh *mshptr , Variable &u_k ,Variable &u_kp1) ;

    


};

#endif