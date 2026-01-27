#pragma once

namespace neon{

struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template<class It>
struct iterator_traits {
    using difference_type = typename It::difference_type;
    using value_type = typename It::value;
    using pointer = typename It::pointer;
    using reference = typename It::reference;
    using iterator_category = typename It::iterator_category;
};

template <class T>
struct iterator_traits<T*> {
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;
    using iterator_category = random_access_iterator_tag;
};

template <class T>
struct iterator_traits<const T*> {
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = const T*;
    using reference         = const T&;
    using iterator_category = random_access_iterator_tag;
};

} // namspace neon