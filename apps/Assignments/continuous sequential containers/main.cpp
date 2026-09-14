//outlined with MS copilot
#include <iostream>
#include <chrono>

#include "Vector.h"
#include "VectorCopy.h"
#include "VectorLarge.h"
#include "Array.h"

using namespace std;
using namespace std::chrono;

void timeVector(const string& label, Vector& v, int n) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
        v.knockback(i);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << label << " - " << n << " elements: " << duration << " ms\n";
}

template <typename T, size_t N>
void arrays(const string& label, Array<T, N>& a) {
    auto start = high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i)
        a[i] = static_cast<T>(i);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << label << " - " << N << " elements: " << duration << " ms\n";
}

int main() {

    Array<int, 32> arr32;
    arr32[0] = 10;
    cout << "Array[0] = " << arr32[0] << "\n\n";

    for (int n = 2; n <= 4096; n *= 2) {
        Vector base;
        timeVector("Base Vector", base, n);

        VectorCopy copy;
        timeVector("Vector (Copy)", copy, n);

        VectorLarge large;
        timeVector("Vector (Large)", large, n);

        if (n == 32) {
            Array<int, 32> arr;
            arrays("Array (32)", arr);
        }
        if (n == 128) {
            Array<int, 128> arr;
            arrays("Array (128)", arr);
        }
        if (n == 512) {
            Array<int, 512> arr;
            arrays("Array (512)", arr);
        }
        if (n == 1024) {
            Array<int, 1024> arr;
            arrays("Array (1024)", arr);
        }

        cout << "-----------------------------\n";
    }

    return 0;
}
