#pragma once
#include "neon/type_traits.h"

namespace neon {

template<class T>
constexpr const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template<class T>
constexpr const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<class It, class T>
It find(It first, It last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) return first;
    }

    return last;
}

template <class OrigIt, class NewIt>
NewIt copy(OrigIt first, OrigIt last, NewIt out) {
    for (; first != last; ++first, ++out) {
        *out = *first;
    }
    return out;
}

template <class OrigIt, class NewIt>
NewIt move(OrigIt first, OrigIt last, NewIt out) {
    for (; first != last; ++first; ++out) {
        *out = neon::move(*first);
    }
    return out;
}

template<class It, class T>
void fill(It first, It last, const T& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}

} // namespace neon