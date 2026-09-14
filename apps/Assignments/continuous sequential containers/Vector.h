//outlined with MS copilot
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
};

#endif
