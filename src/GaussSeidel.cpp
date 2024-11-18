#include "../include/GaussSeidel.h"


void GaussSeidel::compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1){
    // for (int j=0 )

    for (int j =1 ; j< (mshptr->nb_point_ -1) ; j++ ){
        u_kp1[j] = (u_kp1[j-1] + u_k[j+1])/2; 

    }
}
