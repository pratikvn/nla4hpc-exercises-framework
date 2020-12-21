## Summary

In this homework, you will implement a sparse matrix vector multiplication for the CSR matrix format 
on the GPUs.

1. Implement a SpMV with a strategy of your choosing (row parallel, block column, block rows or any combination
 you choose based on your matrix parameters). 
2. Also implement an SpMM operation (Sparse Matrix- Dense Matrix) multiplication. Compare the performance of   this with the above single vector SpMV. 

Your aim is to extract the maximum performance of the GPU.

Copy over the contents in the folder `uxxxx0` to your username specific folder.
Your job is to add the implementation to the `hw6/<your_username>/src/hw6.cpp` file. 

Run `make` and `make test` to check if your implementation is correct and if the tests
implemented in `hw6/tests/hw6.cpp` pass. 

#### Deadlines:

1. Your code should be open for review by Jan 25th. 
2. You will be assigned a review on Jan 25th, you must complete your review by Jan 30th.
3. You will have five more days to finish the updates from the review and submit the code by Jan 
   20th and the code will be merged on Jan 30th.

#### Resources
1. https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html
2. http://docs.nvidia.com/cuda/kepler-tuning-guide/#axzz4WDmkL7pU (For K20s)
3. https://docs.nvidia.com/cuda/volta-tuning-guide/index.html (For V100s)
4. https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#warp-shuffle-functions
