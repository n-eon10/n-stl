#pragma once
#include <cstddef>
#include <new>
#include "neon/type_traits.h"

namespace neon {

/**
 * @brief Allocates raw bytes of memory.
 * @param n Number of bytes to allocate.
 * @return Pointer to the allocated memory block.
 */
void* allocate_bytes(std::size_t n);

/**
 * @brief Deallocates memory.
 * @param p Pointer to the memory block to deallocate.
 */
void deallocate_bytes(void* p) noexcept;

/**
 * @brief Constructs an object pre allocated memory location.
 * @tparam T The type of object to construct.
 * @tparam Args Parameter types for the constructor.
 * @param p Pointer to the memory location where the object will be constructed.
 * @param args Arguments to forward to the constructor.
 * @return Pointer to the newly constructed object.
 */
template <class T, class... Args>
T* construct_at(T* p, Args&&... args){
    return new ((void*)p) T(neon::forward<Args>(args)...)
}

/**
 * @brief Destroys an object by calling its destructor.
 * @tparam T The type of the object to destroy.
 * @param p Pointer to the object to destroy.
 */
template <class T>
void destroy_at(T* p) noexcept {
  p->~T();
}

} // namespace neon