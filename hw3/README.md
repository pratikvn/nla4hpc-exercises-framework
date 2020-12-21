## Summary

In this homework, you will implement a sequential version of the LU factorization. 

1. Given a matrix A, your kernel should output two triangular matrices L and U.

2. Implement pivoting for the LU factorization and add the tests for pivoting.
   Hint: If P is your pivot matrix (if it is a vector, then you need to permute the matrix),
   then PA = LU

Your job is to add the implementation to the `hw3/uxxxx0/src/hw3.cpp` file. 

Run `make` and `make test` to check if your implementation is correct and if the tests
implemented in `hw3/tests/hw3.cpp` pass. 

#### Deadlines:

1. Your code should be open for review by Nov 26th. 
2. You will be assigned a review on Nov 26th, you must complete your review by Dec 1st.
3. You will have five more days to finish the updates from the review and submit the code by Dec 
   6th and the code will be merged on Dec 6th.

#### Important Note:

Feel free to change the function signatures as necessary. 

Also remember to update the declaration in `hw3/uxxxx0/include/hw3.hpp`and where the
functions are called in the tests.

#### Resources

1. A good reference about the concept of pivoting is here] (https://www-old.math.gatech.edu/academic/courses/core/math2601/Web-notes/2num.pdf)

2. [linpack](http://www.netlib.org/linpack/)
   [lapack](http://www.netlib.org/lapack/)
   [dgetrf](http://www.netlib.org/lapack/explore-3.1.1-html/dgetrf.f.html)


## For extra points, 0.25 each.

1. Implement the Crout and Dolittle variants of the LU factorizations.
   Hint: Differences are whether the unit diagonal is on L (Dolittle) or on U (Crout).

2. Implement the factorization in-place, overwrite the matrix with the factors. 

3. Implement the Cholesky factorization, A = L*L^T
