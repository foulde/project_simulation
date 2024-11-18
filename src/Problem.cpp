#include <iostream>
#include <algorithm>
#include <string>

#include "../include/Problem.h"
#include "../include/Equation.h"
#include "../include/Variable.h"
#include "../include/Jacobi.h"
#include "../include/GaussSeidel.h"



#define EPSILON 1e-5


//contient un membre de type equation ---> equation est peut être une classe 


// std::vector<double> Problem::solve(const Equation& eq , int nb_iter) const{
// std::vector<double> Problem::solve(int nb_iter) const{





void Problem::solve(int nb_iter ) const{
    
    Variable u_k(mesh_ptr_); 
    Variable u_kp1(mesh_ptr_); 
        
    std::cout<<"--- Initial condition computation ---\n";
    
    double T1 = 30; 
    double T2 = 15; 

/*FUNCTION FOR UNIFORM DISTRIBUTION*/
    std::function<double(double)>  lambda_UNIFORM = [T1,T2](double x) {return (T1+T2/2);}; 

/*FUNCTION FOR 2 PLATE INITIAL CONDITION */

    std::function<double(double)>  lambda = [this,T1,T2](double x) {
        if (x<=(mesh_ptr_->x_max_ +mesh_ptr_->x_min_)/2)return (T1);
        else return T2; };


    // std::function<double(double)>  lambda = [T1,T2](double x) {return (T1+T2/2);};
    // std::funct   ion<double(double)> = [](double T1 ,double T2  ) {return (T1 +T2)/2;};
    ///////////////////////////////////

/*UNIFORM CHOICE */
    // equation_.compute_initial_condition_lambda(u_k,mesh_ptr_ , lambda_UNIFORM );

    
/*2 PLATE CHOICE */
    equation_.compute_initial_condition_lambda(u_k,mesh_ptr_ , lambda );
    /*we also intialize u_kp1 for method like GaussSeidel  */
    equation_.compute_initial_condition_lambda(u_kp1,mesh_ptr_ , lambda );


    for( int k =1 ; k <=nb_iter  ; k++){
        // std::cout<<"--- Iterative methode iteration : "<<k<<" ---\n";
        // std::cout<<"--- Boundary condition computation ---\n";
        equation_.compute_boundary_conditions(u_k,mesh_ptr_);
        // equation_.compute(mesh_ptr_,u_k, u_kp1);
        equation_.compute_for_solver<Jacobi>(mesh_ptr_,u_k, u_kp1);
        if (has_converged(u_k, u_kp1)){
            std::cout<<"we have converged at the iteration "<<k <<"\n"; 
            break;
        }
        u_k = u_kp1;

        // solution  = eq.compute(mesh_ptr); 
        // solution  = equation_.compute(mesh_ptr_); 
        // compute 
    }
}







void Problem::solve(int nb_iter , std::string method) const{
    
    // nbiter = mesh_ptr_.nb

    // int n_i = mshptr->nb_point; 
    // std::vector<double> solution( mesh_ptr->nb_point, 0);
    // std::vector<double> solution( mesh_ptr_->nb_point_, 0);
    Variable u_k(mesh_ptr_); 
    Variable u_kp1(mesh_ptr_); 
    
    // std::vector<double> solution  ; 
    
    std::cout<<"--- Initial condition computation ---\n";

    
    double T1 = 30; 
    double T2 = 15; 
    // equation_.compute_initial_condition(u_k,mesh_ptr_);

    /*we define get the size of the bar*/
    



    

/*FUNCTION FOR UNIFORM DISTRIBUTION*/
    std::function<double(double)>  lambda_UNIFORM = [T1,T2](double x) {return (T1+T2/2);}; 

/*FUNCTION FOR 2 PLATE INITIAL CONDITION SUPPOSING THE DOMAIN START AT 0*/
    // std::function<double(double)>  lambda = [this,T1,T2](double x) {
    //     if (x<=(mesh_ptr_->x_max_)/2)return (T1);
    //     else return T2; };

/*FUNCTION FOR 2 PLATE INITIAL CONDITION */

    std::function<double(double)>  lambda = [this,T1,T2](double x) {
        if (x<=(mesh_ptr_->x_max_ +mesh_ptr_->x_min_)/2)return (T1);
        else return T2; };


    // std::function<double(double)>  lambda = [T1,T2](double x) {return (T1+T2/2);};
    // std::funct   ion<double(double)> = [](double T1 ,double T2  ) {return (T1 +T2)/2;};
    ///////////////////////////////////

/*UNIFORM CHOICE */
    // equation_.compute_initial_condition_lambda(u_k,mesh_ptr_ , lambda_UNIFORM );
/*2 PLATE CHOICE */
    equation_.compute_initial_condition_lambda(u_k,mesh_ptr_ , lambda );
    /*we also intialize u_kp1 for method like GaussSeidel  */
    equation_.compute_initial_condition_lambda(u_kp1,mesh_ptr_ , lambda );


    for( int k =1 ; k <=nb_iter  ; k++){
        // std::cout<<"--- Iterative methode iteration : "<<k<<" ---\n";
        // std::cout<<"--- Boundary condition computation ---\n";
        
        equation_.compute_boundary_conditions(u_k,mesh_ptr_);
        
        // equation_.compute(mesh_ptr_,u_k, u_kp1);
        if (method == "Jacobi") {equation_.compute_for_solver<Jacobi>(mesh_ptr_,u_k, u_kp1);}
        else if (method =="GaussSeidel"){equation_.compute_for_solver<GaussSeidel>(mesh_ptr_,u_k, u_kp1);}
        else{std::cout<<"you must use Jacobi or GaussSeidel \n";  break;}
        

        if (has_converged(u_k, u_kp1)){
            std::cout<<"we have converged at the iteration "<<k <<"\n"; 
            break;

        }
        u_k = u_kp1;

        // solution  = eq.compute(mesh_ptr); 
        // solution  = equation_.compute(mesh_ptr_); 
        // compute 

    }



}


bool  Problem::has_converged( const Variable &u_k ,const Variable &u_kp1 )const{
    
    double maximum_diff=0.0; 
    // for (int i =0 ; i<u_k.mesh_ptr_->size())
    for (int i =1 ; i<(u_k.mesh_ptr_->x_size())-1 ; i++){

        double diff = std::abs(u_k[i] - u_kp1[i]);
        std::cout<<" the  u_k[i] found is "<<  u_k[i] << "\n";
        std::cout<<" the  u_kp1 found is "<<  u_kp1[i] << "\n";
        std::cout<<" the  diff found is "<<  diff << "\n";

        if (diff>maximum_diff){maximum_diff =diff; } 

    }
    std::cout<<" the maximum diff found in this iteration is "<<  maximum_diff << "\n";
    return maximum_diff<EPSILON; /*return false if maximum diff superior */
}



// int main(){
//     // UniformMesh
//     UniformMesh stmesh; 

    
//     return 0; 
// }
