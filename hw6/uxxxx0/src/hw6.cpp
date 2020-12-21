#include <iostream>
#include <string>

#include "cuda_runtime.h"

#include "../include/hw6.hpp"


template <typename ValueType, typename IndexType>
void csr_spmv(const size_type num_rows, const size_type num_cols,
              const IndexType *csr_row_ptrs, const IndexType *csr_col_idxs,
              const ValueType *csr_values, const ValueType *b_values,
              ValueType *x_values)
{
    // TODO
}


#define NLA4HPC_DECLARE_TO_CSR_CONVERSION(ValueType, IndexType)               \
    void csr_spmv(const size_type num_rows, const size_type num_cols,         \
                  const IndexType *csr_row_ptrs,                              \
                  const IndexType *csr_col_idxs, const ValueType *csr_values, \
                  const ValueType *b_values, ValueType *x_values)

NLA4HPC_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    NLA4HPC_DECLARE_TO_CSR_CONVERSION);
