#pragma once
#include "neon/type_traits.h"

namespace neon {

template<class T>
constexpr const T& min(const T& lhs, const T& rhs) {
    return (rhs < lhs) ? rhs : lhs;
}

template<class T>
constexpr const T& max(const T& lhs, const T& rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

template<class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) return first;
    }

    return last;
}

template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt out) {
    for (; first != last; ++first, ++out) {
        *out = *first;
    }
    return out;
}

template <class InputIt, class OutputIt>
OutputIt move(InputIt first, InputIt last, OutputIt out) {
    for (; first != last; ++first, ++out) {
        *out = neon::move(*first);
    }
    return out;
}

template<class Iterator, class T>
void fill(Iterator first, Iterator last, const T& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}

} // namespace neon