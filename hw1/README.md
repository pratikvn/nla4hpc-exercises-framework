## Summary

In this homework, you will implement three kernels:

1. Euclidean norm of a vector (`norm2`),
2. Matrix vector multiplication of a dense matrix and a vector (`mat_vec`),
3. Matrix matrix multiplication of two dense matrices (`mat_mult`).

Your job is to add the kernel implementations to the `hw1/uxxxx0/src/hw1.cpp` file. 

Run `make` and `make test` to check if your kernel is correct and if the tests
implemented in `hw1/tests/hw1.cpp` pass. 

#### Deadlines:

1. Your code should be open for review by ~~Nov 7th.~~ Nov 12th. 
2. You will be assigned a review on ~~Nov 7th~~ Nov 12th, you must complete your review by ~~Nov 12th~~ Nov 17th.
3. You will have five more days to finish the updates from the review and submit the code by ~~Nov 17th~~ Nov 20th and the
   code will be merged on ~~Nov 17th~~ Nov 20th.

#### Important Note:

Feel free to change the function signature (For the extra credit, you will need to for some of them), remove and add function
parameters to your liking. Not all parameters are needed and some of them are indeed a red herring. But make sure to
update the declaration in `hw1/uxxxx0/include/hw1.hpp`and where the function is called in the tests.

## For extra points, 0.25 each.

1. Add dimension checking (and/or with exception handling) to make sure out of memory acceses due to occur. 
2. Implement `norm2` with complex types, `std::complex<float>` and `std::complex<double>`.
   HINT: Remember that the Euclidean norm
         of a complex vector is still a real value. 

3. Compute `mat_vec` with a user-defined `stride`. 
4. Compute `mat_mult` with a user-defined `stride`. 
 
