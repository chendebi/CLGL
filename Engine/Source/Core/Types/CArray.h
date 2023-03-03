#ifndef CARRAY_H
#define CARRAY_H

#include <vector>

namespace CLGL
{
    template <typename ArrayType>
    using CArray = std::vector<ArrayType>;

    template <typename ArrayType>
    using CArrayIterator  = typename CArray<ArrayType>::iterator;
}

#endif