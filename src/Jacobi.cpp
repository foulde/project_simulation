#include "../include/Jacobi.h"


void Jacobi::compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1){
    // for (int j=0 )

    for (int j =1 ; j< (mshptr->nb_point_ -1) ; j++ ){
        u_kp1[j] = (u_k[j-1] + u_k[j+1])/2; 

    }


}


void Jacobi::compute_iteration_parrallel(IMesh *mshptr , Variable &u_k ,Variable &u_kp1){
    // for (int j=0 )

    auto start = u_k.begin() + 1;
    auto end = u_k.end() - 1;

    // std::for_each(std::execution::par ,u_k.begin()+1, u_k.end()-1, [&](auto& value) {
    std::for_each(std::execution::par ,start, end, [&](auto& value) {
    int index = &value - &u_k[0];/*we take advantage of contiguous nature 
    of value in our datastructure and pointer arithmetics to deduce the index
    of our element */
    double xi = mshptr->x_i(index);           // Get the position from the mesh
    
    u_kp1[index] = (u_k[index-1] + u_k[index+1])/2; 
    });


}

