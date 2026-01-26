#pragma once

namespace neon {

/**
 * @brief Wraps a static constant of specified type.
 * @tparam T The type of the constant.
 * @tparam v The value of the constant.
 */
template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
};

/// @brief Alias for integral_constant<bool, true>.
using true_type = integral_constant<bool, true>;

/// @brief Alias for integral_constant<bool, false>.
using false_type = integral_constant<bool, false>;

/**
 * @brief Checks if two types are the same.
 * @tparam A First type.
 * @tparam B Second type.
 */
template<class A, class B>
struct is_same : false_type {};

template<class A>
struct is_same<A, A> : true_type {};

/**
 * @brief Conditionally enables a type based on a boolean condition.
 * @tparam B The boolean condition.
 * @tparam T The type to enable if B is true.
 */
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> {
    using type = T;
};

/// @brief Helper alias for enable_if.
template<bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;

/**
 * @brief Selects one of two types based on a boolean condition.
 * @tparam B The boolean condition.
 * @tparam T The type if B is true.
 * @tparam F The type if B is false.
 */
template<bool B, class T, class F>
struct conditional {
    using type = T;
};

template<class T, class F>
struct conditional<false, T, F> {
    using type = F;
};

/// @brief Helper alias for conditional.
template<bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;

/**
 * @brief Removes reference qualifiers from a type.
 * @tparam T The type to remove references from.
 */
template<class T>
struct remove_reference {
    using type = T;
};

template<class T>
struct remove_reference<T&> {
    using type = T;
};

template<class T>
struct remove_reference<T&&> {
    using type = T;
};

/// @brief Helper alias for remove_reference.
template<class T>
using remove_reference_t = typename remove_reference<T>::type;

/**
 * @brief Checks if a type is an lvalue reference.
 * @tparam T The type to check.
 */
template<class T>
struct is_lvalue_reference : false_type {};

template<class T>
struct is_lvalue_reference<T&> : true_type {};

/**
 * @brief Casts a value to an rvalue reference, allows move semantics.
 * @tparam T The type of the value.
 * @param t The value to move.
 * @return An rvalue reference to the value.
 */
template<class T>
constexpr remove_reference_t<T>&& move(T&& t) noexcept {
    return static_cast<remove_reference_t<T>&&>(t);
}

/**
 * @brief Forwards an lvalue as either an lvalue or rvalue, preserving value category.
 * @tparam T The type to forward as.
 * @param t The lvalue reference to forward.
 * @return The forwarded reference.
 */
template<class T>
constexpr T&& forward(remove_reference_t<T>& t) noexcept {
    return static_cast<T&&>(t);
}

/**
 * @brief Forwards an rvalue as an rvalue.
 * @tparam T The type to forward as.
 * @param t The rvalue reference to forward.
 * @return The forwarded reference.
 */
template<class T>
constexpr T&& forward(remove_reference_t<T>&& t) noexcept {
    static_assert(!is_lvalue_reference<T>::value, "cannot forward an rvalue as an lvalue");
    return static_cast<T&&>(t);
} 

} 