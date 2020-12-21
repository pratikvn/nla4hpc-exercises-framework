#include <iostream>
#include <string>

#include "cuda_runtime.h"

#include "../include/hw5.hpp"


template <typename ValueType, typename IndexType>
void convert_dense_to_csr(const size_type num_rows, const size_type num_cols,
                          const ValueType *dense_values, IndexType *row_ptrs,
                          IndexType *col_idxs, ValueType *values)
{
    // TODO
}


#define NLA4HPC_DECLARE_TO_CSR_CONVERSION(ValueType, IndexType) \
    void convert_dense_to_csr(                                  \
        const size_type num_rows, const size_type num_cols,     \
        const ValueType *dense_values, IndexType *row_ptrs,     \
        IndexType *col_idxs, ValueType *values)

NLA4HPC_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    NLA4HPC_DECLARE_TO_CSR_CONVERSION);
