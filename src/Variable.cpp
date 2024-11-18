#include <iostream>
#include <vector>
#include "Variable.h"
#include <algorithm>
// #include "../include/Variable.h"




double& Variable::operator[](int index){
    if (index >= mesh_ptr_->x_size() || index <0 ){
        // std::cout<<"index exiding limit \n"; 
        throw std::out_of_range("Index exceeds vector limit in Variable class");
    }
    else{
        return u[index]; 
    }
}

const double& Variable::operator[](int index) const {
    if (index >= mesh_ptr_->x_size() || index < 0) {
        throw std::out_of_range("Index exceeds vector limit in Variable class");
    }
    return u[index]; 
}



double Variable::max_element()const{
    return *std::max_element(u.begin() ,u.end() ); 
}

// double Variable::max_element()const{
 
//     return *std::max_element(u.begin() ,u.end() ); 
// }   

// double Variable::max_element()const{
//     double current = u[0]; 
//     for (int i =0 ; i< (mesh_ptr_->nb_point_ )-1; i++ ){
//         if (current <u[i+1]) current = u[i+1]; 
//     }
//     return current; 
// }


// prout[i]