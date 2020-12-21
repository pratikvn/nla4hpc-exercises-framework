#include <iostream>
#include <string>

#include "include/types.hpp"


template <typename ValueType>
void dot(const ValueType *a, const ValueType *b, const size_type length,
         ValueType &res);


template <typename ValueType>
void axpy(const ValueType *alpha, const ValueType *x, const size_type length,
          ValueType *y);
