
#include <QuEST.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "mbqc.hpp"

// assert library
#include <cassert>
using namespace std;

void testSingleRealisationAssertZeroEnding(int numberQubits){
       // Create QuEST environment
    QuESTEnv env = createQuESTEnv();
    // prepare our register
    Qureg qureg = createQureg(numberQubits, env);

    // qureg -> |+><+|
    initPlusState(qureg);  
    
    // set initial angles
    vector<qreal> qubitAngles;
    for(int i=0;i<numberQubits;i++){
            qubitAngles.push_back(M_PI/2); // Selected all 0.0
        } 
    
    vector<int> outcomes;
    outcomes = runMbqcPathGraph(qureg,qubitAngles,numberQubits);
    
    assert(outcomes.back() == 0);
    assert(outcomes.size()==2);
     // tidy up
    destroyQureg(qureg, env);
    destroyQuESTEnv(env);
}

int main() {
    int numberQubits=2; // As example should work on any odd number qubits

    // Run once
    testSingleRealisationAssertZeroEnding(numberQubits);

    // Run a million times
    for(int i=0;i<1E6;i++)
        testSingleRealisationAssertZeroEnding(numberQubits);
    return 0;
}



