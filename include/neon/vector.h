#pragma once
#include "neon/allocator.h"

namespace neon {

template<class T, class Alloc = neon::allocator<T>>
class vector {
public:
    using value_type = T;
    using size_type = std::size_t;

    using iterator = T*;
    using const_iterator = const T*

    vector() = default;
};
} // namesapce neon