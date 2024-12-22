#include <iostream>
#include <vector>
// #include "Equation.h"
#include "../include/Equation.h"
#include "../include/UniformMesh.h"
#include "../include/IMesh.h"
#include "../include/Variable.h"
#include "../include/Jacobi.h"
#include "../include/GaussSeidel.h"









// std::vector<double> Equation::compute(IMesh * mshptr, Variable &u_k ,Variable &u_kp1 ) const{
void Equation::compute(IMesh * mshptr, Variable &u_k ,Variable &u_kp1 ) const{
    int n_i = mshptr->nb_point_; 
    // std::vector<double> u(n_i, 0);
    // double x_min= mshptr->x_min_;
    // double x_max= mshptr->x_max_;
    // double dx   = abs(x_max-x_min)/n_i;  
#ifdef DEBUG 
    std::cout <<"-- at n_i = "<< n_i <<"\n\n";
#endif 
    // double current_x_i = x_min  ;  /*to avoid error accumulation */
    // for (int i=0 ; i <=n_i ; i++){
    //     current_x_i = x_min +i*dx;   /*to avoid error accumulation */

    //     std::cout <<"i = "<< i <<"\n";
    //     std::cout <<"-- at x_i = "<< current_x_i <<"\n";

    // }

    for (int j =1 ; j< (mshptr->nb_point_ -1) ; j++ ){
        u_kp1[j] = (u_k[j-1] + u_k[j+1])/2; 
        // // // // std::cout <<"-- at j = "<< j 
        // // // //           <<" the value of u = "<<u_kp1[j]
        // // // //           <<"\n";
        // u_k[j] = u_kp1[j];/* bad option because we directly assign u_kp1 to u_k*/

        /*    
        std::cout <<"-- at j = "<< j 
                  <<" the value of u = "<<u_k[j]
                  <<"\n";
    */

    }

}


void Equation::compute_initial_condition(Variable &variable , IMesh *mshptr)const{
    const double T1 = 30; 
    const double T2 = 15;

    // for (int i =0 ; i< (mshtpr->size())/2; i++){
    for (int i =0 ; i< (mshptr->nb_point_)/2; i++){
#ifdef DEBUG 
        std::cout<<"this is the current value of i "<<i<<"\n"; 
#endif
        variable[i]= T1;
        
    } 
    for (int j = (mshptr->nb_point_)/2 ; j< mshptr->nb_point_; j++){

#ifdef DEBUG 
        std::cout<<"this is the current value of i "<<j<<"\n"; 
#endif

        variable[j]= T2;
    } 

}




void Equation::compute_initial_condition_lambda(Variable &variable , IMesh *mshptr 
                                                , std::function<double(double)> initial_condition)const{


    
#ifdef DEBUG
    std::cout<<"Initial condition set up \n"; 
#endif 

//     // for (int i =0 ; i< (mshtpr->size())/2; i++){
//     for (int i =0 ; i< mshptr->nb_point_; i++){
//         // std::cout<<"this is the current value of i "<<i<<"\n"; 
//         double xi = mshptr->x_i(i) ;
//         variable[i]= initial_condition(xi);/*we use the lambda function to apply a x wize treatment to the domain*/
// #ifdef DEBUG 
//         std::cout<<"for i= "<<i <<" x_i = "<<xi<< " Ti = "<< variable[i]<<"\n"; 
// #else       
// #endif

//     }


    std::for_each(std::execution::par ,variable.begin(), variable.end(), [&](auto& value) {
    int index = &value - &variable[0];/*we take advantage of contiguous nature 
    of value in our datastructure and pointer arithmetics to deduce the index
    of our element */
    double xi = mshptr->x_i(index);           // Get the position from the mesh
    value = initial_condition(xi);            // Apply the lambda
    });










#ifdef DEBUG 
    std::cout<<"End of initial condition set up \n\n"; 
#endif



}




void Equation::compute_boundary_conditions(Variable &variable , IMesh *mshptr) const{
    const double T1 = 30; 
    const double T2 = 15;
    variable[0]=T1; 
    variable[mshptr->nb_point_-1]=T2;


}




void Equation::compute_exact_solution(Variable &u_ref ,IMesh * mshptr  )const{
    double T1 =30; 
    double T2 =15; 
    u_ref[0] =30;
    u_ref[mshptr->nb_point_-1] =15; 
    double l=std::abs(mshptr->x_max_ - mshptr->x_min_); 


    // for(int i =1; i<mshptr->nb_point_-1; i++){
        
    //     double xi = mshptr->x_i(i) ;

    //     u_ref[i] =((T2-T1)/l)*(xi) +T1; 
        
    // }


    std::for_each(std::execution::par ,u_ref.begin(), u_ref.end(), [&](auto& value) {
    int index = &value - &u_ref[0];/*we take advantage of contiguous nature 
    of value in our datastructure and pointer arithmetics to deduce the index
    of our element */
    double xi = mshptr->x_i(index);           // Get the position from the mesh
    

    u_ref[index] =((T2-T1)/l)*(xi) +T1; 
    
    });


}









// template<class Method>
// void Equation::compute_for_solver(IMesh *mshptr , Variable &u_k ,Variable &u_kp1)const{

//     int n_i = mshptr->nb_point_;     
//     std::cout <<"-- at n_i = "<< n_i <<"\n\n";

//     // Method::compute_iteration(IMesh *mshptr , Variable &u_k ,Variable &u_kp1);
//     Method::compute_iteration(mshptr , u_k ,u_kp1);

//     // for (int j =1 ; j< (mshptr->nb_point_ -1) ; j++ ){
//     //     u_kp1[j] = (u_k[j-1] + u_k[j+1])/2; 

//     // }

// }





// void Equation::compute_for_solver<Method>(IMesh *mshptr , Variable &u_k ,Variable &u_kp1){}



// int Uni::x_size(){
//     /*no implementation for the moment*/
//     return nb_point_; 
// }

// double IMesh::x_i(int i){
//     return x_min_ +i*
// } 

// int main(){
//     return 0; 
// }