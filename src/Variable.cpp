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

#ifdef DEBUG 

            std::cout<<" "<<u[i] <<" "; 
#endif
            // std::cout<<mesh_ptr_->x_i(i)<<" "<<u[i]; 
            outputFile<<mesh_ptr_->x_i(i)<<" " <<u[i]<<"\n"; 

        }
        outputFile.close(); 

// #ifdef DEBUG 

        std::cout << "Data was written to "<<name<<".data\n";
// #endif
    }


    else{
        
        std::cerr << "Error opening file\n";
    }


}





void Variable::printvtk(std::string name ){



    std::cout<<"this is "<<name <<"\n"; 
    std::ofstream outputFile(name+".vtk");

    if (outputFile.is_open()){


/*
ASCII
DATASET STRUCTURED_POINTS
DIMENSIONS 20 2 2
ORIGIN 0.0 0.0 0.0
SPACING 0.0526316 0.0526316 0.0526316
CELL_DATA 19
SCALARS data float
LOOKUP_TABLE default*/
        // outputFile<<"# vtk Datafile Version 2.0\n" 
        //             <<"Result TD POOCS\n"
        //             <<"ASCII\n"
        //             <<"DATASET STRUCTURED_POINTS\n"
        //             <<"DIMENSIONS "<<mesh_ptr_->nb_point_<<" 2 2\n"
        //             <<"ORIGIN 0.0 0.0 0.0\n"
        //             <<"SPACING "<<mesh_ptr_->m_dx_<<" "<<mesh_ptr_->m_dx_<<" "<<mesh_ptr_->m_dx_<<"\n"
        //             <<"CELL_DATA "<<(mesh_ptr_->nb_point_ -1)<< "\n"
        //             <<"SCALARS data float\n"
        //             <<"LOOKUP_TABLE default\n"; 

        
        
        outputFile << "# vtk DataFile Version 2.0\n"
           << "Result TD POOCS\n"
           << "ASCII\n"
           << "DATASET STRUCTURED_POINTS\n"
           << "DIMENSIONS " << mesh_ptr_->nb_point_ << " 2 2\n"
           << "ORIGIN 0.0 0.0 0.0\n"
           << "SPACING " << mesh_ptr_->m_dx_ << " " << mesh_ptr_->m_dx_ << " " << mesh_ptr_->m_dx_ << "\n"
           << "CELL_DATA " << (mesh_ptr_->nb_point_ - 1) << "\n"
           << "SCALARS data float\n"
           << "LOOKUP_TABLE default\n";
                    



        for (int i =0 ; i < mesh_ptr_->x_size()-1 ;i++ ){

#ifdef DEBUG 

            std::cout<<" "<<u[i] <<" "; 
#endif
            // std::cout<<mesh_ptr_->x_i(i)<<" "<<u[i]; 
            // outputFile<<mesh_ptr_->x_i(i)<<" " <<u[i]<<"\n"; 
            outputFile<<u[i]<<"\n"; 

        }
        outputFile.close(); 

// #ifdef DEBUG 

        std::cout << "Data was written to "<<name<<".vtk\n";
// #endif
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