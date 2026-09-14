//outlined with MS copilot
#include "Vector.h"

Vector::Vector() : data(new int[1]), size(0), capacity(1) {}

Vector::~Vector() {
    delete[] data;
}

void Vector::capacityI() {
    capacity *= 2;
    int* moDat = new int[capacity];

    for (size_t i = 0; i < size; ++i)
        moDat[i] = data[i];

    delete[] data;
    data = moDat;
}

void Vector::knockback(int value) {
    if (size == capacity)
        capacityI();

    data[size++] = value;
}
