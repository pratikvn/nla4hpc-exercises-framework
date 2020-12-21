#include <iostream>
#include <string>

#include "../include/hw4.hpp"


inline size_type linearize_index(size_type row, size_type col,
                                 size_type num_rows)
{
    return row * num_rows + col;
}


template <typename ValueType>
void compute_lu_factorization(const ValueType *mat_a, const size_type num_rows,
                              ValueType *mat_l, ValueType *mat_u)
{
    auto num_threads = omp_get_max_threads();
    // TODO
}


#define NLA4HPC_DECLARE_LU_FAC(ValueType)                                     \
    void compute_lu_factorization(const ValueType *mat_a,                     \
                                  const size_type num_rows, ValueType *mat_l, \
                                  ValueType *mat_u)

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_LU_FAC);
