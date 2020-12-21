#include <iostream>
#include <string>

#include "../include/hw1.hpp"


template <typename ValueType>
void norm2(const ValueType *a, const size_type length, ValueType &res)
{
    // TODO: Implement this
}


template <typename ValueType>
void mat_vec(const ValueType *mat, const size_type num_rows,
             const size_type num_cols, const ValueType *vec,
             const size_type length, ValueType *res)
{
    // TODO: Implement this
}


template <typename ValueType>
void mat_mult(const ValueType *mat_a, const size_type num_rows_a,
              const size_type num_cols_a, const ValueType *mat_b,
              const size_type num_rows_b, const size_type num_cols_b,
              ValueType *mat_res, size_type num_rows_res,
              size_type num_cols_res)
{
    // TODO: Implement this
}


#define NLA4HPC_DECLARE_NORM2(ValueType) \
    void norm2(const ValueType *vec, const size_type length, ValueType &res)

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_NORM2);


#define NLA4HPC_DECLARE_MATVEC(ValueType)                        \
    void mat_vec(const ValueType *mat, const size_type num_rows, \
                 const size_type num_cols, const ValueType *vec, \
                 const size_type length, ValueType *res)

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_MATVEC);


#define NLA4HPC_DECLARE_MATMULT(ValueType)                                \
    void mat_mult(const ValueType *mat_a, const size_type num_rows_a,     \
                  const size_type num_cols_a, const ValueType *mat_b,     \
                  const size_type num_rows_b, const size_type num_cols_b, \
                  ValueType *mat_res, size_type num_rows_res,             \
                  size_type num_cols_res)

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_MATMULT);
