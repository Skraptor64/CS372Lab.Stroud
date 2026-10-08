//outlined in ms copilot
#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

class Vector {
protected:
    int* data;
    size_t size;
    size_t capacity;

public:
    Vector();
    virtual ~Vector();

    void knockback(int value);
    virtual void capacityI();

    class Iterator {
    private:
        int* ptr;        
        size_t index;    

    public:
        Iterator(int* p, size_t i) : ptr(p), index(i) {}

        int& operator*() {
            return ptr[index];
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++index;
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr && index == other.index;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data, size);
    }
};

#endif
