#include <iostream>
#include <string>

#include <omp.h>

#include "include/types.hpp"


template <typename ValueType, typename IndexType>
void convert_dense_to_csr(const size_type num_rows, const size_type num_cols,
                          const ValueType *dense_values,
                          IndexType *csr_row_ptrs, IndexType *csr_col_idxs,
                          ValueType *csr_values);
