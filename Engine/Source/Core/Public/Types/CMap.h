#ifndef CMAP_H
#define CMAP_H
#include <map>

namespace CLGL
{
    template<typename KeyType, typename ValueType>
    using CMap = std::map<KeyType, ValueType>;

    template<typename KeyType, typename ValueType>
    using CMapIterator = typename  std::map<KeyType, ValueType>::iterator;
}

#endif