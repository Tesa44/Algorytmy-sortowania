//
// Created by Mateusz on 02.04.2024.
//

#ifndef SORTINGAPP_QUICKSORT_H
#define SORTINGAPP_QUICKSORT_H

#include <regex>
using namespace std;

template <typename T>

class QuickSort {
public:
    // Metoda pomocniczna do sortowania z lewym pivotem
    //T *arr - tablica do posortowania
    //int start - indeks pierwszego elementu tablicy
    //int end - indeks ostatniego elementu tablicy
    int partitionLeft(T *arr, int start, int end){
        T pivot = arr[start];   //Ustawienie pivota na skrajnie lewy element
        int l = start;
        int r = end;
        while (1) {

            while (arr[l] < pivot)
                ++l;
            while (arr[r] > pivot)
                --r;

            if (l < r) {
                swap(arr[l], arr[r]);
                ++l;
                --r;
            }
            else {
                if (r == end)
                    r--;
                return r;
            }
        }
    }

    // Sortowanie szybkie z lewym pivotem
    //T *arr - tablica do posortowania
    //int start - indeks pierwszego elementu tablicy
    //int end - indeks ostatniego elementu tablicy
    //Do posortowania całej tablicy wpisuje się start = 0 ; end = długość tablicy - 1
    void sortLeft(T *arr,int start,int end){
        if (start >= end)
            return;

        // partitioning the array
        int p = partitionLeft(arr, start, end);

        // Sorting the left part
        sortLeft(arr, start, p);

        // Sorting the right part
        sortLeft(arr, p + 1, end);
    }

    //Metoda pomocniczna do sortowania z prawym pivotem
    int partitionRight(T *arr, int start, int end){
        T pivot = arr[end];     //Ustawienie pivota na skrajnie prawy element
        int l = start;
        int r = end;
        while (1) {

            while (arr[l] < pivot)
                ++l;
            while (arr[r] > pivot)
                --r;

            if (l < r) {
                swap(arr[l], arr[r]);
                ++l;
                --r;
            }
            else {
                if (r == end)
                    r--;
                return r;
            }
        }
    }

    // Sortowanie szybkie z prawym pivotem
    void sortRight(T *arr,int start,int end){
        if (start >= end)
            return;

        // partitioning the array
        int p = partitionRight(arr, start, end);

        // Sorting the left part
        sortRight(arr, start, p);

        // Sorting the right part
        sortRight(arr, p + 1, end);
    }

    //Metoda pomocnicza do sortowania ze środkowym pivotem
    int partitionCenter(T *arr, int start, int end){
        T pivot = arr[(start + end)/2];     //Ustawienie pivota na środkowy element
        int l = start;
        int r = end;
        while (1) {

            while (arr[l] < pivot)
                ++l;
            while (arr[r] > pivot)
                --r;

            if (l < r) {
                swap(arr[l], arr[r]);
                ++l;
                --r;
            }
            else {
                if (r == end)
                    r--;
                return r;
            }
        }
    }
    // Sortowanie szybkie ze środkowym pivotem
    void sortCenter(T *arr,int start,int end){
        if (start >= end)
            return;

        // partitioning the array
        int p = partitionCenter(arr, start, end);

        // Sorting the left part
        sortCenter(arr, start, p);

        // Sorting the right part
        sortCenter(arr, p + 1, end);
    }

    //Metoda pomocnicza do sortowania z losowym pivotem
    int partitionRandom(T *arr, int start, int end) {
        srand(time(0));
        T pivot = arr[start + rand() % (end - start + 1)];  //Ustawienie pivota na losowy element
        int l = start;
        int r = end;
        while (1) {

            while (arr[l] < pivot)
                ++l;
            while (arr[r] > pivot)
                --r;

            if (l < r) {
                swap(arr[l], arr[r]);
                ++l;
                --r;
            } else {
                if (r == end)
                    r--;
                return r;
            }
        }
    }

    // Sortowanie szybkie z losowo ustawionym pivotem
    void sortRandom(T *arr,int start,int end){
        if (start >= end)
            return;

        // partitioning the array
        int p = partitionRandom(arr, start, end);

        // Sorting the left part
        sortRandom(arr, start, p);

        // Sorting the right part
        sortRandom(arr, p + 1, end);
    }
};


#endif //SORTINGAPP_QUICKSORT_H
