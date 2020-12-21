#include <iostream>
#include <string>

#include "../include/hw0.hpp"

template <typename ValueType>
void dot(const ValueType *a, const ValueType *b, const size_type length,
         ValueType &res)
{
    //  Uncomment this
    for (size_type i = 0; i < length; ++i) {
        res += a[i] * b[i];
    }
}


template <typename ValueType>
void axpy(const ValueType *alpha, const ValueType *x, const size_type length,
          ValueType *y)
{
    //  Uncomment this
    for (size_type i = 0; i < length; ++i) {
        y[i] += alpha[0] * x[i];
    }
}


#define NLA4HPC_DECLARE_DOT(_vtype)                                      \
    void dot(const _vtype *a, const _vtype *b, const std::size_t length, \
             _vtype &res);

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_DOT);


#define NLA4HPC_DECLARE_AXPY(_vtype)                                          \
    void axpy(const _vtype *alpha, const _vtype *x, const std::size_t length, \
              _vtype *y);

NLA4HPC_INSTANTIATE_FOR_EACH_POD_TYPE(NLA4HPC_DECLARE_AXPY);
