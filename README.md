# Compaction-of-given-set-of-vectors-to-get-the-same-Fault-Coverage

In this project, the aim is to remove the redundant vectors which do not contribute in improving the fault coverage. For example, if given 100 vectors can calculate, fault coverage of say 80%, it is possible that not all the given 100 vectors are high quality vectors. We can get the same fault coverage of 80% for say 50 vectors, hence removing the unnecessary vectors.

Compilation Instructions : In the terminal, make sure you are including all the header files.

Compile the code using g++ -Iinclude include/verilated.cpp Vtop__Syms.cpp Vtop.cpp Main_project1.cpp Then open the output.vec file which contains the reduced set of vectors

lev_vec.vec is the input file containing all the given vectors. The first line in this file indicates the number of inputs for a given circuit. Set Vector is the first vector and reset vector is the last vector