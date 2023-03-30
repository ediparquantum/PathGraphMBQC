<img src="https://user-images.githubusercontent.com/19248072/225727493-def23a0b-96e3-4310-aa9b-5f27fb0c6f2a.png"  width="300" height="200">

# pathGraphMBQC
Implementing QuEST quantum mechanics toolbox in path graphs MBQC.

Measurement Based Quantum Computation (MBQC) is a different model for performing quantum computation from the ciruit base model. An abstract graph (nodes and edges) is the base of the MBQC. In this repository we focus on the path graph only.

The path graph, P, consists of a graph that can be represented as a single line of edges and nodes. 

<img src="https://user-images.githubusercontent.com/19248072/225726167-6cf3710d-db2c-479c-be50-f8f9ce9ed101.png"  width="300" height="=30">


To perform the computation we initialise all qubits in the plus state and a list of angles corresponding to each qubit. The computation is performed one qubit at a time. The first qubit is rotated in the Z-axis by the negative value of the first angle and then the Hadamard gate is applied, then the qubit is measured in the compurational basis. This process is repeated for all of the qubits. The caveat is that each subsequent qubit uses previous qubits to update the angle of that current qubit.

In the root `CMakeLists.txt` file add `set(CMAKE_CXX_STANDARD 11)` to set the compiler to C++11 (at least on Mac this had to be done).

A simple example is presented in `runSimpleMbqcPathGraph.cpp` and can be run in conjunction with QuEST. Place this repository in the main directory of QuEST and run

Once the project is in quest, here is a simple example to execute the above script inside the `build` directory.

```
cmake .. -DUSER_SOURCE="projects/PathGraphMBQC/runSimpleMbqcPathGraph.cpp" -DOUTPUT_EXE="runSimpleMbqcPathGraph" && make && ./runSimpleMbqcPathGraph
```

Note that the root folder is QuEST, a subfolder called `project` has been created and inside is the `runSimpleMbqcPathGraph.hpp` file. There are other options to use in `cmake`, but see the QuEST repository for further instructions.

## QuEST
website: [https://quest.qtechtheory.org/](https://quest.qtechtheory.org/) 
github: [https://github.com/QuEST-Kit/QuEST](https://github.com/QuEST-Kit/QuEST)


## To do
- [ ] Test functionality on density matrix for mixed states
- [ ] Test on different path graph mbqc circuits

