#include <QuEST.h>
//#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>    // std::all_of
#include <string>
#include "mbqc.hpp"
using namespace std;




int main() {

    // Create QuEST environment
    QuESTEnv env = createQuESTEnv();
    // set parameters
    int numberQubits = 5; // Any number
    // prepare our register
    Qureg qureg = createQureg(numberQubits, env);
    
    // set initial angles
    vector<qreal> qubitAngles;
    for(int i=0;i<numberQubits;i++){
            qubitAngles.push_back(0.0); // Selected all 0.0
        } 
    
    vector<int> outcomes;
    outcomes = runMbqcPathGraph(qureg,qubitAngles,numberQubits);
    
    for(int i: outcomes){
        cout << i << " ";
    }
}

