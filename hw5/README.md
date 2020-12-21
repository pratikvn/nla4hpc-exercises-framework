## Summary

In this homework, you will implement a conversion routine from a Dense matrix to a CSR matrix. 

Allocate the Dense matrix on the host and copy it over to the GPU.

1. Identify the number of nonzero elements in the distinct rows (in parallel).
2. Get the total number of nonzeros via reduction.
3. Allocate the memory needed to store the CSR matrix.
4. Fill the CSR structure with the nonzero elements (in parallel).

Copy by the CSR matrix to the host and verify its correctness. 

The test gives you a Dense matrix and its raw pointer. The output is then expected in the three raw pointers which essentially represent the CSR matrix.

Copy over the contents in the folder `uxxxx0` to your username specific folder.
Your job is to add the implementation to the `hw5/<your_username>/src/hw5.cpp` file. 

Run `make` and `make test` to check if your implementation is correct and if the tests
implemented in `hw5/tests/hw5.cpp` pass. 

#### Deadlines:

1. Your code should be open for review by Jan 10th. 
2. You will be assigned a review on Jan 10th, you must complete your review by Jan 15th.
3. You will have five more days to finish the updates from the review and submit the code by Jan 
   20th and the code will be merged on Jan 20th.

#### Important Note:

This is the start of the CUDA exercises and you will probably be needing the kernels/class framework you write
for the exercises that follow. The next exercise is an SpMV and the last CUDA exercise is a Krylov solver. Therefore, make sure to write your kernels with this in mind. 

Separate out your CSR and Dense matrices into classes with appropriate member functions and variables. You will then be able to use the same code for the future exercises making your job much easier.
