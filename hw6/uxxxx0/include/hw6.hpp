#include <iostream>
#include <string>

#include <omp.h>

#include "include/types.hpp"


template <typename ValueType, typename IndexType>
void csr_spmv(const size_type num_rows, const size_type num_cols,
              const IndexType *csr_row_ptrs, const IndexType *csr_col_idxs,
              const ValueType *csr_values, const ValueType *bvalues,
              ValueType *xvalues);
