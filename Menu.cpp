//
// Created by Mateusz on 01.04.2024.
//
#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::listMenu() {
    while (true) {
        cout << "Witaj w menu programu" << endl;
        cout << "1. Uzyj ostatnio utworzona tablice" << endl;
        cout << "2. Wygeneruj tablice zawierajaca losowe wartosci" << endl;
        cout << "3. Wczytaj tablice z pliku o zadanej nazwie" << endl;
        cout << "4. Tryb do testowania szybkosci algorytmow sortowania" << endl;
        cin >> listChoice;
        if (checkChoices(listChoice, '4'))
            return;
    }
}

void Menu::sortMenu() {
    while (true) {
        cout << "Wybierz algorytm sortowania dla ostatnio utworzonej lub wczytanej tablicy" << endl;
        cout << "1. Sortowanie przez wstawianie" << endl;
        cout << "2. Sortowanie przez kopcowanie" << endl;
        cout << "3. Sortowanie Shella" << endl;
        cout << "4. Sortowanie szybkie" << endl;
        cin >> sortChoice;
        if (checkChoices(sortChoice, '4'))
            return;
    }
}

int Menu::inputLen() {
    string input;
    bool guard;
    while (true) {
        guard = true;
        cout << "Podaj dlugosc tablicy, ktora ma zostac wygenerowana" << endl;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i] == false))
                guard = false;
        }
        if (guard) {
            int n = stoi(input);
            return n;
        }
        cout << "To nie jest liczba" << endl;
    }
}
    //Metoda służy do sprawdzania czy wybór wpisany przez użytkownika jest zgodny z jakimkolwiek wyborem
    //char choice - znak podany przez użytkownika określający wybór
    //char choiceQuantity - ile posiadamy wyborów w menu
bool Menu::checkChoices(char choice, char choiceQuantity) {
    if (choice >= '1' && choice <= choiceQuantity)
        return true;
    cout << "Niepoprawny wybor!" << endl;
    return false;
}
    //Komunikat do podania ścieżki do pliku tekstowego
string Menu::inputPath() {
    string path;
    cout << "Podaj sciezke do pliku tekstowego " << endl;
    cin >> path;
    return path;
}
    //Menu dla wyboru pivota w sortowaniu szybkim
void Menu::quickSortMenu() {
    while (true) {
        cout << "Wybierz miejsce pivota dla sortowania szybkiego" << endl;
        cout << "1. Skrajnie lewy pivot" << endl;
        cout << "2. Skrajnie prawy pivot" << endl;
        cout << "3. Srodkowy pivot" << endl;
        cout << "4. Losowy pivot" << endl;
        cin >> quickSortChoice;
        if (checkChoices(quickSortChoice,'4'))
            return;
    }
}

    //Menu do wyboru wzoru, z którego oblicza się przerwy w sortowaniu Shella
void Menu::shellSortMenu() {
    while (true) {
        cout << "Wybierz wzor tworzacy algorytm dla sortowania Shella" << endl;
        cout << "1. N / 2^k" << endl;
        cout << "2. (3^k - 1)/2" << endl;
        cin >> shellSortChoice;
        if (checkChoices(shellSortChoice, '2'))
            return;
    }
}

void Menu::displayMenu() {
    while (true) {
        cout << "Czy wyswietlic posortowana tablice?" << endl;
        cout << "1. Tak" << endl;
        cout << "2. Nie" << endl;
        cin >> displayChoice;
        if (checkChoices(displayChoice, '2'))
            return;
    }
}

    //Menu wyświetlane na samym końcu programu, możemy zacząć od początku lub wyjść z programu
void Menu::exitRepeatMenu() {
    while (true) {
        cout << "Czy chcesz wyjsc z programu?" << endl;
        cout << "1. Posortuj jeszcze raz" << endl;
        cout << "2. Zamknij program" << endl;
        cin >> exitRepeatChoice;
        if (checkChoices(exitRepeatChoice, '2'))
            return;
    }
}

    //Menu do podania ilości testów do trybu testowania czasów sortowań
int Menu::inputNumberOfTests() {
    string input;
    bool guard;
    while (true) {
        guard = true;
        cout << "Podaj liczbe testow, z ktorych zostanie obliczony sredni czas wybranego sortowania" << endl;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i] == false))     //Sprawdzanie czy każdy podany znak jest liczbą
                guard = false;
        }
        if (guard) {
            int numberOfTests = stoi(input);    //Konwertowanie string na int
            return numberOfTests;
        }
        cout << "To nie jest liczba" << endl;
    }
}

    //Menu do wyboru rodzaju tablicy, która ma zostać wygenerowana do testowania.
void Menu::arrayTypeMenu() {
    while (true) {
        cout << "Wybierz rodzaj tablicy do wygenerowania" << endl;
        cout << "1. Calkowicie losowa" << endl;
        cout << "2. Posortowana w 33%" << endl;
        cout << "3. Posortowana w 66%" << endl;
        cout << "4. Posortowana odwrotnie (malejaco)" << endl;
        cout << "5. Posortowana calkowicie" << endl;
        cin >> arrayTypeChoice;
        if (checkChoices(arrayTypeChoice,'5'))
            return;
    }
}
