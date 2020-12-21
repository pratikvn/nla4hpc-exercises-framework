## Summary

In this homework, you will implement an OMP parallel version of the LU factorization. 

1. Given a matrix A, your kernel should output two triangular matrices L and U. You should be able to use
   the framework from HW3. 

2. Implement a simple parallel for the loops and analyze the speedups. 

3. Implement a task based tiled LU factorization as explained in Lecture 4. 

Copy over the contents in the folder `uxxxx0` to your username specific folder.
Your job is to add the implementation to the `hw4/<your_username>/src/hw4.cpp` file. 

Run `make` and `make test` to check if your implementation is correct and if the tests
implemented in `hw4/tests/hw4.cpp` pass. 

#### Deadlines:

1. Your code should be open for review by Dec 13th. 
2. You will be assigned a review on Dec 13th, you must complete your review by Dec 23th.
3. You will have seven more days to finish the updates from the review and submit the code by Dec 
   23th and the code will be merged on Dec 30th.

#### Important Note:

Though the function signature here specifies that L and U matrices are explicit matrices, if for performance reasons
you want to use an in-place factorization, please feel free to do so.,

## For extra points, 0.5 each.

1. Implement the Cholesky version of the tile factorization, A = L*L^T
