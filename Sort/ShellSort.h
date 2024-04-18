//
// Created by Mateusz on 02.04.2024.
//

#ifndef SORTINGAPP_SHELLSORT_H
#define SORTINGAPP_SHELLSORT_H

#include <valarray>
#include "../Model.h"

template <typename T>
class ShellSort {
public:
    void sort(T *arr, int n){
        for (int gap = n/2; gap > 0; gap /= 2)
        {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire array is
            // gap sorted
            for (int i = gap; i < n; i += 1)
            {
                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                T temp = arr[i];

                // shift earlier gap-sorted elements up until the correct
                // location for a[i] is found
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                //  put temp (the original a[i]) in its correct location
                arr[j] = temp;
            }
        }
    }
    void sortKnuth(T *arr,int n) {
        int h = 1;
        while (h < n / 3) {
            h = 3 * h + 1;      //Obliczenie ostatniego wyrazu ciągu Knutha mieszczącego się w długości tablicy.
        }

        // Rozpoczęcie sortowania Shella z użyciem ciągu Knutha
        while (h >= 1) {
            for (int i = h; i < n; ++i) {
                T key = arr[i];
                int j = i;
                while (j >= h && arr[j - h] > key) {
                    arr[j] = arr[j - h];
                    j -= h;
                }
                arr[j] = key;
            }
            h /= 3;     //Zmniejszanie przerwy zgodnie z ciągiem Knutha
        }
    }

};

#endif //SORTINGAPP_SHELLSORT_H
