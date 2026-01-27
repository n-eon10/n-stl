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

template <class It1, class It2>
bool equal(It1 first1, It1 last1, It2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (!(*first1 == *first2)) return false;
  }
  return true;
}

template <class It1, class It2>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2) {
  for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
  }
  return (first1 == last1) && (first2 != last2);
}

} // namespace neon