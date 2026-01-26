#pragma once

namespace neon {

/**
 * @brief Swaps values of two objects.
 * @tparam T The type of the objects to swap.
 * @param a First object.
 * @param b Second object.
 */
template<class T> 
void swap(T& a, T& b) noexcept {
    T temp_val = neon::move(a);
    a = neon::move(b);
    b = neon::move(temp_val);
}

/**
 * @brief A simple container holding two heterogeneous values.
 * @tparam T1 The type of the first element.
 * @tparam T2 The type of the second element.
 */
template<class T1, class T2>
struct pair {
    T1 first;   
    T2 second;  

    /// @brief Default constructor
    constexpr pair() : first(), second() {}

    /**
     * @brief Constructs a pair from two values.
     * @param a Value to init first.
     * @param b Value to init second.
     */
    constexpr pair(const T1& a, const T2& b) : first(a), second(b) {}
};

}