#include <iostream>
#include <string>

#include "include/types.hpp"


template <typename ValueType>
void compute_lu_factorization(const ValueType *mat_a, const size_type num_rows,
                              ValueType *mat_l, ValueType *mat_u);
