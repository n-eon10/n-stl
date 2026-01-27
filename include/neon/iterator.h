#pragma once

namespace neon{

/**
 * @brief Tag type for input iterators.
 * Defines an iterator category for iterators that can only read values in a forward direction.
 */
struct input_iterator_tag {};

/**
 * @brief Tag type for forward iterators.
 * Defines an iterator category for iterators that can read values in a forward direction multiple times.
 */
struct forward_iterator_tag : input_iterator_tag {};

/**
 * @brief Tag type for bidirectional iterators.
 * Defines an iterator category for iterators that can read values in both forward and backward directions.
 */
struct bidirectional_iterator_tag : forward_iterator_tag {};

/**
 * @brief Tag type for random access iterators.
 * Defines an iterator category for iterators that support random access in constant time.
 */
struct random_access_iterator_tag : bidirectional_iterator_tag {};

/**
 * @brief Provides type information about iterators.
 * @tparam It The iterator type.
 */
template<class It>
struct iterator_traits {
    /// @brief The type used to represent distances between iterators.
    using difference_type = typename It::difference_type;
    /// @brief The type of values accessed through the iterator.
    using value_type = typename It::value;
    /// @brief The type of pointers to the iterated values.
    using pointer = typename It::pointer;
    /// @brief The type of references to the iterated values.
    using reference = typename It::reference;
    /// @brief The iterator category tag.
    using iterator_category = typename It::iterator_category;
};

/**
 * @brief Specialisation of iterator_traits for raw pointers.
 * @tparam T The type being pointed to.
 */
template <class T>
struct iterator_traits<T*> {
    /// @brief The type used to represent distances between pointers.
    using difference_type   = std::ptrdiff_t;
    /// @brief The type of values accessed through the pointer.
    using value_type        = T;
    /// @brief The type of the pointer itself.
    using pointer           = T*;
    /// @brief The type of references to the pointed to values.
    using reference         = T&;
    /// @brief Pointers are random access iterators.
    using iterator_category = random_access_iterator_tag;
};

/**
 * @brief Specialisation of iterator_traits for const pointers.
 * @tparam T The type being pointed to.
 */
template <class T>
struct iterator_traits<const T*> {
    /// @brief The type used to represent distances between const pointers.
    using difference_type   = std::ptrdiff_t;
    /// @brief The type of values accessed through the const pointer.
    using value_type        = T;
    /// @brief The type of the const pointer itself.
    using pointer           = const T*;
    /// @brief The type of const references to the pointed-to values.
    using reference         = const T&;
    /// @brief Const pointers are random access iterators.
    using iterator_category = random_access_iterator_tag;
};

} // namspace neon