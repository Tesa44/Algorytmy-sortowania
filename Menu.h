//
// Created by Mateusz on 01.04.2024.
//

#ifndef SORTINGAPP_MENU_H
#define SORTINGAPP_MENU_H
#include <iostream>
using namespace std;

class Menu {
public:
    char listChoice;
    char sortChoice;
    char quickSortChoice;
    char shellSortChoice;
    char displayChoice;
    char arrayTypeChoice;
    char exitRepeatChoice;
    void listMenu();
    void sortMenu();
    int inputLen();
    string inputPath();
    bool checkChoices(char choice, char choiceQuantity);
    void quickSortMenu();
    void shellSortMenu();
    void displayMenu();
    void exitRepeatMenu();
    int inputNumberOfTests();
    void arrayTypeMenu();
};


#endif //SORTINGAPP_MENU_H
