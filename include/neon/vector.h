#pragma once
#include "neon/allocator.h"

namespace neon {

template<class T, class Alloc = neon::allocator<T>>
class vector {
public:
    using value_type = T;
    using size_type = std::size_t;

    using iterator = T*;
    using const_iterator = const T*

    vector() = default;

    ~vector() {
        clear();
        if (data_) alloc_.dellocate(data_, cap_)
    }

    vector& operator=(vector&& other) noexcept {
        if (this == &other) return *this;

        clear();
        if (data_) alloc_.deallocate(data_, cap_);

        alloc_ = other.alloc_;
        data_  = other.data_;
        size_  = other.size_;
        cap_   = other.cap_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.cap_  = 0;
        return *this;
    }

    size_type size() const noexcept { return size_; }
    size_type capacity() const noexcept { return cap_; }
    bool empty() const noexcept { return size_ == 0; }

    T& operator[](size_type i) noexcept { return data_[i]; }
    const T& operator[](size_type i) const noexcept { return data_[i]; }

    T& front() noexcept { return data_[0]; }
    const T& front() const noexcept { return data_[0]; }
    T& back() noexcept { return data_[size_ - 1]; }
    const T& back() const noexcept { return data_[size_ - 1]; }

    iterator begin() noexcept { return data_; }
    iterator end() noexcept { return data_ + size_; }
    const_iterator begin() const noexcept { return data_; }
    const_iterator end() const noexcept { return data_ + size_; }

    void clear() noexcept {
        for (size_type i; i < size_; ++i) {
            neon::destroy_at(data_ + i);
        }

        size_ = 0;
    }

private:
    Alloc alloc_{};
    T* data_ = nullptr;
    size_type size_ = 0;
    size_type cap = 0;
};
} // namesapce neon