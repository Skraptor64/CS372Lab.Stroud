//outlined with MS copilot
#include "VectorCopy.h"
#include <algorithm>

void VectorCopy::capacityI() {
    capacity *= 2;
    int* moDat = new int[capacity];

    std::copy(data, data + size, moDat);

    delete[] data;
    data = moDat;
}
