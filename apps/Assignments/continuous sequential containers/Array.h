//outlined with MS copilot
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class Array {
private:
    T data[N];
    std::size_t size;

public:
    Array() : size(N) {}

    std::size_t getSize() const {
        return size;
    }

    T& operator[](std::size_t index) {
        if (index >= size)
            throw std::out_of_range("Array index out of range");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= size)
            throw std::out_of_range("Array index out of range");
        return data[index];
    }

    void knockback(const T& value) {
        throw std::logic_error("Array<T,N> does not support dynamic insertion");
    }
};

#endif
