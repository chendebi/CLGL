#ifndef CLIST_H
#define CLIST_H

#include <list>

namespace CLGL
{
    template <typename ListType>
    using CList = std::list<ListType>;

    template <typename ListType>
    using CListIterator  = typename CList<ListType>::iterator;
}

#endif