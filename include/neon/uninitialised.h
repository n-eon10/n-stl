#pragma once
#include <cstddef>
#include "neon/memory.h"
#include "neon/type_traits.h"

namespace neon {

/**
 * @brief Destroys objects in  first to last in reverse order.
 * @tparam T type of objects to destroy.
 * @param first Pointer to the start of the range.
 * @param last Pointer to the end of the range.
 */
template <class T>
void destroy_range(T* first, T* last) noexcept {
  while (first != last) {
    --last;
    neon::destroy_at(last);
  }
}

/**
 * @brief Copies objects from one uninitialised range to another.
 * @tparam T type of objects to copy.
 * @param first Pointer to the start of the source range.
 * @param last Pointer to the end of the source range.
 * @param dest Pointer to the start of the destination range.
 * @return Pointer to the end of the constructed range.
 */
template <class T>
T* uninitialised_copy(const T* first, const T* last, T* dest) {
  T* cur = dest;
  try {
    for (; first != last; ++first, ++cur)
      neon::construct_at(cur, *first);
    return cur;
  } catch (...) {
    destroy_range(dest, cur);
    throw;
  }
}

/**
 * @brief Moves objects from one uninitialised range to another.
 * @tparam T The type of objects to move.
 * @param first Pointer to the start of the source range.
 * @param last Pointer to the end of the source range.
 * @param dest Pointer to the start of the destination range.
 * @return Pointer to the end of the constructed range.
 */
template <class T>
T* uninitialised_move(T* first, T* last, T* dest) {
  T* cur = dest;
  try {
    for (; first != last; ++first, ++cur)
      neon::construct_at(cur, neon::move(*first));
    return cur;
  } catch (...) {
    destroy_range(dest, cur);
    throw;
  }
}

/**
 * @brief Fills n uninitialised objects with a given value.
 * @tparam T The type of objects to construct.
 * @param dest Pointer to the start of the destination range.
 * @param n Number of objects to construct.
 * @param value The value to copy into each object.
 * @return Pointer to end of the constructed range.
 */
template <class T>
T* uninitialised_fill_n(T* dest, std::size_t n, const T& value) {
  T* cur = dest;
  try {
    for (std::size_t i = 0; i < n; ++i, ++cur)
      neon::construct_at(cur, value);
    return cur;
  } catch (...) {
    destroy_range(dest, cur);
    throw;
  }
}

} // namespace neon
