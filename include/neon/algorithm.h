#pragma once
#include "neon/type_traits.h"

namespace neon {

/**
 * @brief Returns the smaller of two values.
 * @tparam T The type of values to compare.
 * @param lhs The left-hand side value.
 * @param rhs The right-hand side value.
 * @return A const reference to the smaller value.
 */
template<class T>
constexpr const T& min(const T& lhs, const T& rhs) {
    return (rhs < lhs) ? rhs : lhs;
}

/**
 * @brief Returns the larger of two values.
 * @tparam T The type of values to compare.
 * @param lhs The left-hand side value.
 * @param rhs The right-hand side value.
 * @return A const reference to the larger value.
 */
template<class T>
constexpr const T& max(const T& lhs, const T& rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

/**
 * @brief Finds the first element equal to the specified value.
 * @tparam Iterator The type of iterator.
 * @tparam T The type of value to search for.
 * @param first The start of the range to search.
 * @param last The end of the range to search.
 * @param value The value to search for.
 * @return An iterator to the first matching element, or last if no match is found.
 */
template<class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) return first;
    }

    return last;
}

/**
 * @brief Copies a range of elements to another range.
 * @tparam InputIt The type of input iterator.
 * @tparam OutputIt The type of output iterator.
 * @param first The start of the range to copy.
 * @param last The end of the range to copy.
 * @param out The start of the destination range.
 * @return An iterator to the element following the last copied element.
 */
template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt out) {
    for (; first != last; ++first, ++out) {
        *out = *first;
    }
    return out;
}

/**
 * @brief Moves a range of elements to another range.
 * @tparam InputIt The type of input iterator.
 * @tparam OutputIt The type of output iterator.
 * @param first The start of the range to move.
 * @param last The end of the range to move.
 * @param out The start of the destination range.
 * @return An iterator to the element following the last moved element.
 */
template <class InputIt, class OutputIt>
OutputIt move(InputIt first, InputIt last, OutputIt out) {
    for (; first != last; ++first, ++out) {
        *out = neon::move(*first);
    }
    return out;
}

/**
 * @brief Fills a range with the specified value.
 * @tparam Iterator The type of iterator.
 * @tparam T The type of value to fill with.
 * @param first The start of the range to fill.
 * @param last The end of the range to fill.
 * @param value The value to fill with.
 */
template<class Iterator, class T>
void fill(Iterator first, Iterator last, const T& value) {
    for (; first != last; ++first) {
        *first = value;
    }
}

/**
 * @brief Checks if two ranges are equal.
 * @tparam It1 The type of iterator for the first range.
 * @tparam It2 The type of iterator for the second range.
 * @param first1 The start of the first range.
 * @param last1 The end of the first range.
 * @param first2 The start of the second range.
 * @return true if all elements in the ranges are equal, false otherwise.
 */
template <class It1, class It2>
bool equal(It1 first1, It1 last1, It2 first2) {
  for (; first1 != last1; ++first1, ++first2) {
    if (!(*first1 == *first2)) return false;
  }
  return true;
}

/**
 * @brief Checks if the first range is lexicographically less than the second range.
 * @tparam It1 The type of iterator for the first range.
 * @tparam It2 The type of iterator for the second range.
 * @param first1 The start of the first range.
 * @param last1 The end of the first range.
 * @param first2 The start of the second range.
 * @param last2 The end of the second range.
 * @return true if the first range is lexicographically less than the second, false otherwise.
 */
template <class It1, class It2>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2) {
  for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
  }
  return (first1 == last1) && (first2 != last2);
}

} // namespace neon