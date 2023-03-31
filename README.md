<img src="https://user-images.githubusercontent.com/19248072/225727493-def23a0b-96e3-4310-aa9b-5f27fb0c6f2a.png"  width="300" height="200">

# pathGraphMBQC
Implementing QuEST quantum mechanics toolbox in path graphs MBQC.

Measurement Based Quantum Computation (MBQC) is a different model for performing quantum computation from the ciruit base model. An abstract graph (vertices and edges) is the base representation of the MBQC and a subsquent quantum computation is defined by the graph. In this repository we focus on the path graph only. The path graph, $P$, consists of a graph that can be represented as a single line of edges and vertices. 

<img src="https://user-images.githubusercontent.com/19248072/225726167-6cf3710d-db2c-479c-be50-f8f9ce9ed101.png"  width="300" height="=30">

The graph, $P$ is made up of two sets, $V$ and $E$, for vertices and edges respectively. We can write a list of the vertices and edges as 

$$P = (v_1,e_1,v_2,e_2,..,e_{n-1},v_n)$$
 
We let each vertex $v_i$ represent a qubit, $q_i$ of $n$ qubits, and for each $q_i$ there is a corresponding angle used in measuring the qubits, call it $\phi_i$. In an arbitrary MBQC, we have a graph, $G$, a vector of angles, $\mathrm{\mathbf{\phi}}$, and a function, $f$ defining the mapping of an input qubit to a future qubit, with its inverse mapping an input qubit to a past qubit. In $P$, $f(q_i) = q_{i+1}$ and $f^{-1}(q_i) = q_{i-1}$. 

To perform the computation we initialise all qubits in the plus state. Then we take the first qubit and rotate around the $Z$ axis, $RZ(-\phi_1)$, then perform the $H$ gate on $q_1$, then measure in the computational basis. The second measurement computes an updated angle, $\phi'_2$ as

$$\phi'_2 = (-1)^{s_{f^{-1}(2)}}\phi_2 = (-1)^{s_1}\phi_2.$$

Then we perform the same tasks of $RZ(-\phi'_2)$, then perform the $H$ gate on $q_2$, then measure in the computational basis. From the third qubit untill the final qubit the angles are updated as 

$$\phi'_i = (-1)^{s_{f^{-1}(i)}}\phi_i + \pi \left( f^{-1}\circ f^{-1}(q_i) \right) = (-1)^{s_{i-1}}\phi_2 + \pi s_{i-2}.$$

For an arbitraty graph, the flow function may not be so straightforward to compute, but for $P$ we can see it is straightforward. As before, once the updated angle for the qubit to be measured is computed, then perform the $RZ(-\phi'_i)H$ gates, then measure $q_i$ in the computational basis. Each measurement causes the quantum state to project onto a smaller subspace iteratively until the desired number of qubits has been measured. 

To run the path graph functionality, one must first download the QuEST toolkit. 

1. Download QuEST from the [QueST downloads page](https://quest.qtechtheory.org/download/)
2. Alternatively go to the [QuEST GitHub page](https://github.com/QuEST-Kit/QuEST)

Once QuEST is downloaded into a folder location in your system the following has been done 

1. In the root `CMakeLists.txt` file add `set(CMAKE_CXX_STANDARD 11)` to set the compiler to C++11 (at least on Mac this had to be done).

After QuEST is set up, download or clone this repository into a subfolder of the QuEST directory, `QuEST/projects/PathGraphMBQC/` for example. A simple example is presented in `runSimpleMbqcPathGraph.cpp` and can be run in conjunction with QuEST. Place this repository in the main directory of QuEST and run

```
cmake .. -DUSER_SOURCE="projects/PathGraphMBQC/runSimpleMbqcPathGraph.cpp" -DOUTPUT_EXE="runSimpleMbqcPathGraph" && make && ./runSimpleMbqcPathGraph
```

QuEST uses cmake and there are several compiling options, which can be found in the [QuEST compiling documentation](https://github.com/QuEST-Kit/QuEST/blob/master/examples/README.md#compiling) page.


## Tests
So far three tests have been completed.

1. The last qubit should measure $0$
   1. Set an odd numbner of qubits and all initial angles at $0$ (`oddNumberQubitAnglesAllZero.cpp`)
   2. Set an odd number of qubits, every second angle is $0$ and the sum of angles is a multiple of $2n\pi$ (`oddNumberQubitsEverySecondsAngleZero.cpp`)
   3. Set $2$ qubits and each angle is $\pi/2$ (`twoQubitsAnglesPiOnTwo.cpp`)
2. The last qubit should measure $1$
    1. Set an odd number of qubits, every second angle is $0$ and the sum of angles is a multiple of $2n\pi + \pi$ (`oddNumberQubitsEverySecondsAngleZero.cpp`) 

Note that all of these test and functions have been written with pure states in mind.
## To do
- [ ] Test functionality on density matrix for mixed states
- [ ] Test on different path graph mbqc circuits
- [x] Include script testing that on an odd number of qubits with all angles being set to 0, that the last qubit is always a 0.
- [x] Test that on two qubits with both angles being set to pi/2 that the last qubit is always 0.
- [x] Test that on an odd number qubits and every second angle being set to zero that if the sum of the angles is a multiple of 2pi than the last qubit is 0, if a multiple of 2pi + pi then the last qubit is 1.


