#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "Variable.h"
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



void Variable::print(std::string name ){
    std::cout<<"this is "<<name <<"\n"; 
    std::ofstream outputFile(name+".data");

    if (outputFile.is_open()){

        for (int i =0 ; i < mesh_ptr_->x_size() ;i++ ){
             
            std::cout<<" "<<u[i] <<" "; 
            // std::cout<<mesh_ptr_->x_i(i)<<" "<<u[i]; 
            outputFile<<mesh_ptr_->x_i(i)<<" " <<u[i]<<"\n"; 

        }
        outputFile.close(); 
        std::cout << "Data was written to output.txt\n";
    }


    else{
        std::cerr << "Error opening file\n";
    }


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