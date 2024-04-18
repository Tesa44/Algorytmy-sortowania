//
// Created by Mateusz on 03.04.2024.
//

#ifndef SORTINGAPP_MODEL_H
#define SORTINGAPP_MODEL_H

#include <string>
#include <fstream>

using namespace std;
template <class T>

class Model {

public:
    T *array;       //Wskaźnik na tablicę dynamiczną
    T *arrayCopy;   //Wskaźnik na kopię dynamicznej tablicy
    int n;          //Długość tablicy dynamicznej

    //Metoda, która generuje losową tablicę. Długość jest brana ze zmiennej n
    //char type - 'i' lub 'f' . Określa jaki typ danych ma być w generowanej tablicy
    void generateArray(char type) {
        srand(time(0));
        if (type == 'i') {
            for (int i = 0; i < n; i++) {
                array[i] = rand() % (n * 4);
            }
        }
        if (type == 'f') {
            for (int i = 0 ; i < n ; i++){
                array[i] =  static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/9000));
            }
        }
    }
    //Wczytaj tablicę z pliku tekstowego
    //string path - pełna ścieżka do pliku tekstowego
    void loadArray(string path) {
        fstream file;
        file.open(path, ios_base::in);
        file >> n;
        //cout << n;
        initArray(n);
        for (int i = 0; i < n; i++) {
            file >> array[i];
        }
    }

    //Metoda, która wyświetla tablicę
    //T *array - wskaźnik na tablicę do wyświetlania
    //int n - długość tablicy
    void displayArray(T *array, int n){
        cout << "[ ";
        for (int i = 0; i < n-1 ; i ++) {
            cout << array[i] << ", ";
        }
        cout << array[n-1] << " ]" << endl;
    }

    //Metoda do kopiowania tablicy
    //T *array - wskaźnik na tablicę, którą będziemy kopiować
    //T *arrayCopy - wskaźnik na tablicę, do której będziemy kopiować
    //int n - długość tablicy
    void copyArray(T *array, T *arrayCopy, int n){
        for (int i = 0 ; i < n ; i++)
            arrayCopy[i] = array[i];
    }
    //Metoda do tworzenia dynamicznej tablicy
    //int n - długość tablicy dynamicznej do utworzenia
    void initArray(int n){
        array = new T[n];
    }
    void initArrayCopy(int n){
        arrayCopy = new T[n];
    }

    //Metoda do częściowego posortowania tablicy
    //T *arr - wskaźnik na tablicę, która ma zostać częściowo posortowana
    //int percent - procent, w którym tablica ma zostać posortowana (0-100)
    void sortPartially(T *arr, int percent){
        if (percent <= 0 or percent > 100) //Jeśli wartość w procentach jest niepoprawna to ustaw na 50%
            percent = 50;
        QuickSort<T> quickSort;
        quickSort.sortLeft(arr,0,n-1); //Sortowanie całej tablicy za pomocą quick sort
        int start = n*percent/100;  //Obliczanie indeksu od którego należy mieszać elementy w tablicy
        srand(time(0));
        int randomPlace;
        //Mieszanie tablicy za pomocą generowania losowych indeksów i zamieniania miesjcem elementów.
        for (int i = start; i < n; i++){
            randomPlace = rand()%(n - start + 1) + start - 1;
            swap(arr[i],arr[randomPlace]);
        }
    }

    //Metoda do posortowania tablicy odwrotnie (malejąco)
    //T *arr - tablica, która ma zostać posortowana odwrotnie
    void sortInversely(T *arr) {
        QuickSort<T> quickSort;
        quickSort.sortLeft(arr,0,n-1);  //Sortowanie całej tablicy za pomocą quick sort

        for (int i = 0; i <n/2; i++){
            swap(arr[i],arr[n-i-1]);    //Zamiana pierwszego elementu z ostatnim itp.
        }
    }

    //Metoda sprawdzająca czy tablica jest posortowana rosnąco
    //T *arr - tablica do sprawdzenia
    //int n - długość tablicy sprawdzanej
    //string option - "default" lub "test". Opcja "default" wyświetla komunikat wyniku sprawdzenia tablicy dla jednego badania
                                        //  Opcja "test" jest dla trybu testu szybkości sortowań. Skrócony komunikat o wyniku sprawdzenia.
    //Funkcja zwraca wiadomość, czy tablica jest posortowana czy nie
    string checkIfArraySorted(T *arr, int n, string option = "default"){
        string msgSorted;
        string msgNotSorted;
        if (option == "test") {
            msgSorted = "Zaliczony";
            msgNotSorted = "Niezaliczony";
        }
        else {
            msgSorted = "Tablica zostala posortowana poprawnie \n";
            msgNotSorted = "Tablica nie zostala posortowana poprawnie \n";
        }

        for (int i = 0; i < n - 1; i ++){
            if (arr[i] > arr[i+1])
                return msgNotSorted;
        }
        return msgSorted;
    }
};


#endif //SORTINGAPP_MODEL_H
