# PathGraphMBQC
Implementing QuEST quantum mechanics toolbox in path graphs MBQC.

Measurement Based Quantum Computation (MBQC) is a different model for performing quantum computation from the ciruit base model. An abstract graph (nodes and edges) is the base of the MBQC. In this repository we focus on the path graph only.

The path graph, P, consists of a graph that can be represented as a single line of edges and nodes. To perform the computation we initialise all qubits in the plus state and a list of angles corresponding to each qubit. The computation is performed one qubit at a time. The first qubit is rotated in the Z-axis by the negative value of the first angle and then the Hadamard gate is applied, then the qubit is measured in the compurational basis. This process is repeated for all of the qubits. The caveat is that each subsequent qubit uses previous qubits to update the angle of that current qubit.

A simple example is presented in `runSimpleMbqcPathGraph.cpp` and can be run in conjunction with QuEST. Place this repository in the main directory of QuEST and run

