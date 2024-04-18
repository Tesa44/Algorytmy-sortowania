//
// Created by Mateusz on 01.04.2024.
//

#ifndef SORTINGAPP_APP_H
#define SORTINGAPP_APP_H

#include "Menu.h"
#include "Sort/InsertionSort.h"
#include "Sort/QuickSort.h"
#include "Sort/ShellSort.h"
#include "Sort/HeapSort.h"
#include "Model.h"
#include <chrono>

using namespace std::chrono;

template <typename T>
class App {
public:
    char type; //Określenie typu danych w tablicy: 'i' - int ; 'f' - float
    Menu menu;
    Model<T> model;
    InsertionSort<T> insertionSort;
    QuickSort<T> quickSort;
    ShellSort<T> shellSort;
    HeapSort<T> heapSort;
    int durTime = 0; //Czas wykonywania pojedynczego sortowania [ms]
    bool emptyFlag = true; // Flaga,czy istnieje tablica do ponownego posortowania
    int numberOfTests; // ilość testów do wykonania w trybie testowania algorytmów sortowania

    //Metoda, która steruje główną częścią programu, w zależności od wyborów w menu. Obudowa menu
    void run() {
        while (true) {
            runListMenu();
            if (menu.listChoice == '4')
                runSortTests();
            else
                runSortMenu();

            menu.exitRepeatMenu();
            if (menu.exitRepeatChoice == '2')
                return;
            emptyFlag = false;
        }
    }

    //Metoda, która steruje dalszymi etapami programu, w zależności od wyboru w ListMenu(). Następuje tutaj wybór dotyczący używanej tablicy
    void runListMenu() {
        menu.listMenu();
        switch (menu.listChoice) {
            case '1':               //Użyj ostatnio wczytaną/wygenerowaną tablicę
                if (emptyFlag) {
                    cout << "Nie masz utworzonej tablicy" << endl;
                    model.n = menu.inputLen();
                    model.initArray(model.n);
                    model.generateArray(type);
                    model.displayArray(model.array, model.n);
                }
                else {
                    cout << "Twoja tablica to: " << endl;
                    model.displayArray(model.array, model.n);
                }
                break;
            case '2':               //Wygeneruj losową tablicę o podanej długości
                model.n = menu.inputLen();
                model.initArray(model.n);
                model.generateArray(type);
                menu.arrayTypeMenu();       //Wyswietlanie menu dotyczącego wyboru generowania tablicy
                switch (menu.arrayTypeChoice) {
                    case '1':       //Tablica całkowicie losowa
                        break;
                    case '2':       //Tablica posortowana w 33%
                        model.sortPartially(model.array,33);
                        break;
                    case '3':       //Tablica posortowana w 66%
                        model.sortPartially(model.array, 66);
                        break;
                    case '4':       //Tablica posortowana odwrotnie
                        model.sortInversely(model.array);
                        break;
                    case '5':       //Tablica posortowana
                        quickSort.sortCenter(model.array,0 , model.n - 1);
                        break;
                }
                cout << "Wygenerowana tablica: " << endl;
                model.displayArray(model.array, model.n);   //Wyświetlenie wygenerowanej tablicy
                break;
            case '3':               //Wczytaj tablicę z pliku .txt. Trzeba podać ścieżkę do pliku
                string path = menu.inputPath();
                //cout << path;
                //model.initArray(model.n);
                model.loadArray(path);
                model.displayArray(model.array, model.n);
                break;
        }
    }

    // Metoda odpowiedzialna za włączanie odpowiednich algorytmów sortowania w zależności od wyboru w menu.
    void runSortMenu() {
        menu.sortMenu();
        model.initArrayCopy(model.n);
        model.copyArray(model.array,model.arrayCopy,model.n);
        //Zmienne używane do obliczania czasu trwania sortowania
        auto begin = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();;
        auto diff = duration_cast<milliseconds>(begin - end); // Różnica czasu między begin i end

        switch(menu.sortChoice) {
            case '1':           //Sortowanie przez wstawianie
                begin = std::chrono::steady_clock::now();       //Zczytaj czas przed włączeniem sortowania
                insertionSort.sort(model.arrayCopy,model.n);
                end = std::chrono::steady_clock::now();         //Zczytaj czas po sortowania
                diff = duration_cast<milliseconds>(end - begin);    //Liczenie różnicy czasu w celu obliczenia czasu trwania sortowania
                durTime = diff.count();     //Przekonweruj dane z diff na liczbę całkowitą, która oznacza czas w milisekundach.
                break;
            case '2':       //Sortowanie kopcowe
                begin = std::chrono::steady_clock::now();
                heapSort.sort(model.arrayCopy, model.n);
                end = std::chrono::steady_clock::now();
                diff = duration_cast<milliseconds>(end - begin);
                durTime = diff.count();
                break;
            case '3':       //Sortowanie Shella
                menu.shellSortMenu();
                switch (menu.shellSortChoice) {
                    case '1':       //Przerwy wybieranie standardowo
                        begin = std::chrono::steady_clock::now();
                        shellSort.sort(model.arrayCopy,model.n);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    case '2':       //Przerwy wybieranie według ciągu Knutha
                        begin = std::chrono::steady_clock::now();
                        shellSort.sortKnuth(model.arrayCopy,model.n);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    default:
                        cout << "Error!";
                        break;
                }
                break;
            case '4':       //Sortowanie szybkie
                menu.quickSortMenu();
                switch (menu.quickSortChoice) {
                    case '1':       //Lewy pivot
                        begin = std::chrono::steady_clock::now();
                        quickSort.sortLeft(model.arrayCopy,0,model.n-1);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    case '2':       //Prawy pivot
                        begin = std::chrono::steady_clock::now();
                        quickSort.sortRight(model.arrayCopy,0,model.n-1);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    case '3':       //Srodkowy pivot
                        begin = std::chrono::steady_clock::now();
                        quickSort.sortCenter(model.arrayCopy,0,model.n-1);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    case '4':       //Losowy pivot
                        begin = std::chrono::steady_clock::now();
                        quickSort.sortRandom(model.arrayCopy,0,model.n-1);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        durTime = diff.count();
                        break;
                    default:
                        cout << "Error";
                        break;
                }
                break;
            default:
                cout << "Error";
                break;
        }
        std::cout << "Czas sortowania to: " << durTime << "[ms]" << std::endl;
        cout << "Sprawdzanie poprawnosci sortowania tablicy ... " << endl;
        cout << model.checkIfArraySorted(model.arrayCopy,model.n);  //Informacja, czy tablica zostala posortowana.
        menu.displayMenu();     //wyświetlenie menu z zapytaniem czy wyświetlić posortowaną tablicę
        switch (menu.displayChoice) {
            case '1':
                model.displayArray(model.arrayCopy,model.n);
                break;
            default:
                break;
        }
    }

    //Metoda stworzona do testowania czasu algorytmów sortowania. Jest to zmieniona metoda runSortMenu(). Jest bardziej zautomatyzowana
    void runSortTests(){
        menu.sortMenu();    //Wyswietl menu, żeby wybrać algorytm sortowania do testów
        numberOfTests = menu.inputNumberOfTests();  //Podaj ilość testów na daną partię danych w tablicy
        auto begin = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        auto diff = duration_cast<milliseconds>(begin - end);
        int arrLens[7] = {10000,20000,40000,80000,160000,320000,640000}; //7 długości tablic danych do testowania szybkości
        double *sortTimeResults = new double[7];    //Tablica, która przetrzymuje średnie wyniki czasu sortowania z każdej partii danych

        for (int i = 0 ; i < 7 ; i ++) {    //Pętla do wykonywania testów na kolejnych długościach tablic danych do sortowania
            model.n = arrLens[i];       //Bierzemy po kolei długości tablic danych do testowania z arrLens
            model.initArray(model.n);   //Tworzymy tablicę dynamiczną o długość wziętej wyżej
            double totalDurTime = 0;        //Zmienna do sumowania wyników testów, służy do obliczenia średniej
            double avgDurTime = 0;
            for (int j = 0 ; j < numberOfTests ; j ++){     //Petla do wykonywania testów
                model.generateArray(type);                  //Wygeneruj losową tablicę dla każdego testu
                if (i == 0 and j == 0)
                    menu.arrayTypeMenu(); //Zapytaj o wybór generowania tablicy tylko przed pierwszym testem. Dla kolejnych testow zachowaj ten wybór i nie pytaj więcej
                switch (menu.arrayTypeChoice) {
                    case '1':       //Tablica całkowicie losowa
                        break;
                    case '2':       //Tablica posortowana w 33%
                        model.sortPartially(model.array,33);
                        break;
                    case '3':       //Tablica posortowana w 66%
                        model.sortPartially(model.array, 66);
                        break;
                    case '4':       //Tablica posortowana odwrotnie
                        model.sortInversely(model.array);
                        break;
                    case '5':       //Tablica posortowana
                        quickSort.sortCenter(model.array,0 , model.n - 1);
                        break;
                }
                switch(menu.sortChoice) {
                    case '1':       //Sortowanie przez wstawianie
                        begin = std::chrono::steady_clock::now();
                        insertionSort.sort(model.array,model.n);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        totalDurTime += diff.count();       //Dodaj czas testu do sumy wszystkich testów
                        break;
                    case '2':       //Sortowanie przez kopcowanie
                        begin = std::chrono::steady_clock::now();
                        heapSort.sort(model.array, model.n);
                        end = std::chrono::steady_clock::now();
                        diff = duration_cast<milliseconds>(end - begin);
                        totalDurTime += diff.count();
                        break;
                    case '3':   //Sortowanie Shella
                        if (i == 0 and j == 0)  //Zapytaj o wybór wzoru na przerwy tylko przed pierwszym testem. Dla kolejnych testow zachowaj ten wybór i nie pytaj więcej
                            menu.shellSortMenu();
                        switch (menu.shellSortChoice) {
                            case '1':       //Przerwy wybierane standardowo
                                begin = std::chrono::steady_clock::now();
                                shellSort.sort(model.array,model.n);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            case '2':       //Przerwy wybieranie według ciągu Knutha
                                begin = std::chrono::steady_clock::now();
                                shellSort.sortKnuth(model.array,model.n);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            default:
                                cout << "Error!";
                                break;
                        }
                        break;
                    case '4':       //Sortowanie szybkie
                        if (i == 0 and j == 0)  //Zapytaj o wybór pivota tylko przed pierwszym testem. Dla kolejnych testów zachowaj ten wybór
                            menu.quickSortMenu();
                        switch (menu.quickSortChoice) {
                            case '1':       //Lewy pivot
                                begin = std::chrono::steady_clock::now();
                                quickSort.sortLeft(model.array,0,model.n-1);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            case '2':       //Prawy pivot
                                begin = std::chrono::steady_clock::now();
                                quickSort.sortRight(model.array,0,model.n-1);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            case '3':       //Srodkowy pivot
                                begin = std::chrono::steady_clock::now();
                                quickSort.sortCenter(model.array,0,model.n-1);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            case '4':       //Losowy pivot
                                begin = std::chrono::steady_clock::now();
                                quickSort.sortRandom(model.array,0,model.n-1);
                                end = std::chrono::steady_clock::now();
                                diff = duration_cast<milliseconds>(end - begin);
                                totalDurTime += diff.count();
                                break;
                            default:
                                cout << "Error";
                                break;
                        }
                        break;
                    default:
                        cout << "Error";
                        break;
                }
                cout << "Test" << j << ": ";
                cout << model.checkIfArraySorted(model.array,model.n, "test");  //Informacja o poprawności posortowania tablicy
                cout << " w czasie  " << diff.count() << "[ms]" << endl;    //Informacja o czasie sortowania dla danego testu

            }
            avgDurTime = totalDurTime / numberOfTests;  //Obliczanie średniej z czasów sortowania wszytkich testow dla danej długości tablicy
            cout << endl << "Sredni czas sortowania " << model.n << " elementow to: " << avgDurTime << " [ms]" << endl;
            sortTimeResults[i] = avgDurTime;
            delete[] model.array;   //Usuwanie dynamicznej tablicy, ponieważ w następnej pętli trzeba utworzyć nową o innej długości
        }
        cout << "------- Podsumowanie -------" << endl;     //Wyświetlanie podusmowania zawierającego średnie czasy sortowania dla wszystkich długości
        for (int i = 0; i < 7; i ++){
            cout << "Sredni czas sortowania " << arrLens[i] << " elementow to " << sortTimeResults[i] << endl;
        }
        cout << endl;
    }
};



#endif //SORTINGAPP_APP_H
