#include<stdlib.h>
#include<vector>
#include<iostream>
#include "../include/UniformMesh.h"



int UniformMesh::x_size(){
    return nb_point_; 
}


double UniformMesh::x_i(int i){
    return x_min_ + i * m_dx_;


}



