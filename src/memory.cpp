#include "neon/memory.h"
#include <new>

namespace neon {

/**
 * @brief Allocates raw bytes of memory.
 * @param n Number of bytes to allocate.
 * @return Pointer to the allocated memory block.
 */
void* allocate_bytes(std::size_t n) {
    return operator new(n);
};

/**
 * @brief Deallocates memory.
 * @param p Pointer to the memory block to deallocate.
 */
void deallocate_bytes(void* p) noexcept {
    return operator delete(p);
}
} // namespace neon