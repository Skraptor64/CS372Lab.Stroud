//outlined with MS copilot
#include "VectorLarge.h"
#include <algorithm>

VectorLarge::VectorLarge() {
    delete[] data;
    capacity = 128;
    size = 0;
    data = new int[capacity];
}

void VectorLarge::capacityI() {
    capacity *= 4;
    int* newData = new int[capacity];

    std::copy(data, data + size, newData);

    delete[] data;
    data = newData;
}
