//
// Created by Mateusz on 02.04.2024.
//

#ifndef SORTINGAPP_INSERTIONSORT_H
#define SORTINGAPP_INSERTIONSORT_H
using namespace std;

template <class T>
class InsertionSort {
public:
    void sort(T *arr, int n){
        int i, j;
        T key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            // Move elements of arr[0..i-1],
            // that are greater than key,
            // to one position ahead of their
            // current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};


#endif //SORTINGAPP_INSERTIONSORT_H
