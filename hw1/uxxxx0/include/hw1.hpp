#include <iostream>
#include <string>

#include "include/types.hpp"


template <typename ValueType>
void norm2(const ValueType *vec, const size_type length, ValueType &res);


template <typename ValueType>
void mat_vec(const ValueType *mat, const size_type num_rows,
             const size_type num_cols, const ValueType *vec,
             const size_type length, ValueType *res);


template <typename ValueType>
void mat_mult(const ValueType *mat_a, const size_type num_rows_a,
              const size_type num_cols_a, const ValueType *mat_b,
              const size_type num_rows_b, const size_type num_cols_b,
              ValueType *mat_res, size_type num_rows_res,
              size_type num_cols_res);
