
#include <QuEST.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "mbqc.hpp"

// assert library
#include <cassert>
using namespace std;

void testSingleRealisationAssertZeroEnding(int numberQubits,vector<qreal> qubitAngles,int assertConditionValue){
       // Create QuEST environment
    QuESTEnv env = createQuESTEnv();
    // prepare our register
    Qureg qureg = createQureg(numberQubits, env);

    // qureg -> |+><+|
    initPlusState(qureg);  
    
    vector<int> outcomes;
    outcomes = runMbqcPathGraph(qureg,qubitAngles,numberQubits);
    
    assert(outcomes.back() == assertConditionValue);
    assert(outcomes.size()==numberQubits);
     // tidy up
    destroyQureg(qureg, env);
    destroyQuESTEnv(env);
}

int main() {
    // As example should work on any odd number qubits
    int numberQubits=7; 

    // Test: multiple of 2pi last qubit should be 0
    //
    //
    // set initial angles
    vector<qreal> qubitAngles0;
    for(int i=0;i<numberQubits;i++){
        if(i%2==0){
            qubitAngles0.push_back(2*M_PI); // Selected all 0.0
        }else if(i%2==1){
            qubitAngles0.push_back(0.0); // Selected all 0.0
        }else{
            //nothing
        }
    }
    
    int assertConditionValue0 = 0;
    // Run once 
    testSingleRealisationAssertZeroEnding(numberQubits,qubitAngles0,assertConditionValue0);
    
    // Run a million times
    for(int i=0;i<1E6;i++)
        testSingleRealisationAssertZeroEnding(numberQubits,qubitAngles0,assertConditionValue0);


    // Test: multiple of 2pi last qubit should be 0
    //
    //
    // set initial angles
    vector<qreal> qubitAngles1;
    for(int i=0;i<numberQubits;i++){
        if(i%2==0){
            qubitAngles1.push_back(2*M_PI); // Selected all 0.0
        }else if(i%2==1){
            qubitAngles1.push_back(0.0); // Selected all 0.0
        }else{
            //nothing
        }
    }
    qubitAngles1.back()=M_PI;
        
    int assertConditionValue1 = 1;
    // Run once 
    testSingleRealisationAssertZeroEnding(numberQubits,qubitAngles1,assertConditionValue1);
    
    // Run a million times
    for(int i=0;i<1E6;i++)
        testSingleRealisationAssertZeroEnding(numberQubits,qubitAngles1,assertConditionValue1);

    return 0;
}


