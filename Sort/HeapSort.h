//
// Created by Mateusz on 02.04.2024.
//

#ifndef SORTINGAPP_HEAPSORT_H
#define SORTINGAPP_HEAPSORT_H

#include <regex>
using namespace std;

template <typename T>
class HeapSort {
public:
    void heapify(T *arr, int N, int i) {
        // Initialize largest as root
        int largest = i;

        // left = 2*i + 1
        int l = 2 * i + 1;

        // right = 2*i + 2
        int r = 2 * i + 2;

        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest
        // so far
        if (r < N && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected
            // subtree
            heapify(arr, N, largest);
        }
    }

    void sort(T *arr, int N) {
        // Build heap (rearrange array)
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);

        // One by one extract an element
        // from heap
        for (int i = N - 1; i > 0; i--) {

            // Move current root to end
            swap(arr[0], arr[i]);

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    };
};


#endif //SORTINGAPP_HEAPSORT_H
