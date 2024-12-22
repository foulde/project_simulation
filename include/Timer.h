#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>

struct Timer{
    
    public : 

    inline void tstart(){    
        start = std::chrono::system_clock::now();
    }

    inline void tstop(){
        stop = std::chrono::system_clock::now();
        
    }

    inline void print(){
        
        std::chrono::duration<double> elapsed_seconds = stop - start;

        // std::cout <<"this part has taken  "<< (stop-start) <<std::endl; 
        std::time_t  end_time = std::chrono::system_clock::to_time_t(stop);

        std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

    
    } 

    private: 
    

    std::chrono::time_point<std::chrono::system_clock> start, stop;
    // double  start ;
    // double  stop ; 



    
};

#endif