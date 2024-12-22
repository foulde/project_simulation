#include <iostream>
#include <algorithm>
#include <string>

#include "../include/Problem.h"
#include "../include/Equation.h"
#include "../include/Variable.h"
#include "../include/Jacobi.h"
#include "../include/GaussSeidel.h"



#define EPSILON 1e-5





/*Default use Jacobi non parrallel*/
void Problem::solve(int nb_iter ) const{ 
    
    Variable u_k(mesh_ptr_); 
    Variable u_kp1(mesh_ptr_); 
#ifdef DEBUG 
    std::cout<<"--- Initial condition computation ---\n";
#endif

    double T1 = 30; 
    double T2 = 15; 

/*FUNCTION FOR UNIFORM DISTRIBUTION*/
    std::function<double(double)>  lambda_UNIFORM = [T1,T2](double x) {return (T1+T2/2);}; 

/*FUNCTION FOR 2 PLATE INITIAL CONDITION */

    std::function<double(double)>  lambda = [this,T1,T2](double x) {
        if (x<=(mesh_ptr_->x_max_ +mesh_ptr_->x_min_)/2)return (T1);
        else return T2; };

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
        // equation_.compute_for_solver<Jacobi>(mesh_ptr_,u_k, u_kp1);

        equation_.compute_for_solver<Jacobi>(mesh_ptr_, u_k, u_kp1, Jacobi::compute_iteration);

        if (has_converged(u_k, u_kp1)){
#ifdef DEBUG 
            std::cout<<"we have converged at the iteration "<<k <<"\n"; 
#endif
            break;
        }
        u_k = u_kp1;

        // solution  = eq.compute(mesh_ptr); 
        // solution  = equation_.compute(mesh_ptr_); 
        // compute 
    }
}










void Problem::solve(int nb_iter , std::string method) const{

    Variable u_k(mesh_ptr_); 
    Variable u_kp1(mesh_ptr_); 
    Variable u_ref(mesh_ptr_); 
    
#ifdef DEBUG 
    std::cout<<"--- Initial condition computation ---\n";
#endif 
    
    double T1 = 30; 
    double T2 = 15; 

    



    

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
    
#ifdef DEBUG 
    u_kp1.print("initial");
#endif

    /*We compute the exact solutions */
    equation_.compute_exact_solution(u_ref,mesh_ptr_  );

    
    /*compute boundary condition */
    equation_.compute_boundary_conditions(u_k,mesh_ptr_);


    for( int k =1 ; k <=nb_iter  ; k++){
        // std::cout<<"--- Iterative methode iteration : "<<k<<" ---\n";
        // std::cout<<"--- Boundary condition computation ---\n";
        
        // equation_.compute_boundary_conditions(u_k,mesh_ptr_);
        
        // equation_.compute(mesh_ptr_,u_k, u_kp1);
        if (method == "Jacobi") {equation_.compute_for_solver<Jacobi>(mesh_ptr_, u_k, u_kp1, Jacobi::compute_iteration);}
        
        else if (method =="GaussSeidel"){
        equation_.compute_for_solver<GaussSeidel>(mesh_ptr_, u_k, u_kp1, GaussSeidel::compute_iteration);
        }
        
        else{std::cout<<"you must use Jacobi or GaussSeidel \n";  break;}
        

        if (has_converged(u_k, u_kp1)){
// #ifdef DEBUG 
            std::cout<<"we have converged at the iteration "<<k <<"\n"; 
// #endif          
            break;

        }
        u_k = u_kp1;

        // solution  = eq.compute(mesh_ptr); 
        // solution  = equation_.compute(mesh_ptr_); 
        // compute 

    }

    /*we now write the data to separate files */
    u_kp1.print("ukp1"); 
    u_ref.print("u_ref"); 

    u_kp1.printvtk("ukp1_paraview"); 
    u_ref.printvtk("u_ref_paraview"); 

    

}











void Problem::solve_parallel(int nb_iter , std::string method) const{

    Variable u_k(mesh_ptr_); 
    Variable u_kp1(mesh_ptr_); 
    Variable u_ref(mesh_ptr_); 
    
#ifdef DEBUG 
    std::cout<<"--- Initial condition computation ---\n";
#endif 
    
    double T1 = 30; 
    double T2 = 15; 

    



    

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
    
#ifdef DEBUG 
    u_kp1.print("initial");
#endif

    /*We compute the exact solutions */
    equation_.compute_exact_solution(u_ref,mesh_ptr_  );

    
    /*compute boundary condition */
    equation_.compute_boundary_conditions(u_k,mesh_ptr_);


    for( int k =1 ; k <=nb_iter  ; k++){
        // std::cout<<"--- Iterative methode iteration : "<<k<<" ---\n";
        // std::cout<<"--- Boundary condition computation ---\n";
        
        // equation_.compute_boundary_conditions(u_k,mesh_ptr_);
        
        // equation_.compute(mesh_ptr_,u_k, u_kp1);
        if (method == "Jacobi") {equation_.compute_for_solver<Jacobi>(mesh_ptr_, u_k, u_kp1, Jacobi::compute_iteration_parrallel);}
        
        else if (method =="GaussSeidel"){
        equation_.compute_for_solver<GaussSeidel>(mesh_ptr_, u_k, u_kp1, GaussSeidel::compute_iteration);
        }
        else{std::cout<<"you must use Jacobi or GaussSeidel \n";  break;}
        

        if (has_converged(u_k, u_kp1)){
// #ifdef DEBUG 
            std::cout<<"we have converged at the iteration "<<k <<"\n"; 
// #endif          
            break;

        }
        u_k = u_kp1;

        // solution  = eq.compute(mesh_ptr); 
        // solution  = equation_.compute(mesh_ptr_); 
        // compute 

    }

    /*we now write the data to separate files */
    u_kp1.print("ukp1"); 
    u_ref.print("u_ref"); 

    u_kp1.printvtk("ukp1_paraview"); 
    u_ref.printvtk("u_ref_paraview"); 

    

}

































bool  Problem::has_converged( const Variable &u_k ,const Variable &u_kp1 )const{
    
    double maximum_diff=0.0; 
    // for (int i =0 ; i<u_k.mesh_ptr_->size())
    for (int i =1 ; i<(u_k.mesh_ptr_->x_size())-1 ; i++){

        double diff = std::abs(u_k[i] - u_kp1[i]);
#ifdef DEBUG 
        std::cout<<" the  u_k[i] found is "<<  u_k[i] << "\n";
        std::cout<<" the  u_kp1 found is "<<  u_kp1[i] << "\n";
        std::cout<<" the  diff found is "<<  diff << "\n";
#endif

        if (diff>maximum_diff){maximum_diff =diff; } 

    }

#ifdef DEBUG 
    std::cout<<" the maximum diff found in this iteration is "<<  maximum_diff << "\n";
#endif

    return maximum_diff<EPSILON; /*return false if maximum diff superior */
}




