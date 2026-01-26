#pragma once
#include "neon/memory.h"

namespace neon {

/**
 * @brief A memory allocator for type T.
 * @tparam T The type of objects to allocate.
 */
template <class T>
struct allocator
{
    /// @brief The type of objects being allocated.
    using val_type = T;

    /**
     * @brief Allocates memory for n objects of type T.
     * @param n Number of objects to allocate.
     * @return Pointer to the allocated memory block.
     */
    T* allocate(std::size_t n) {
        return static_cast<T*>(neon::allocate_bytes(n * sizeof(T)))
    }

    /**
     * @brief Deallocates previously allocated memory.
     * @param p Pointer to the memory block to deallocate.
     * @param n Number of objects (unused).
     */
    void deallocate(T* p, std::size_t /*n*/) noexcept {
        neon::deallocate_bytes(p);
    }
};

} // namespace neon