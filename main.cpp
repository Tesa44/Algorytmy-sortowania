#include <iostream>
#include "App.h"

int main() {
    cout << "Witaj w programie SortingApp" << endl;
    cout << "Autor: Mateusz Tesarewicz" << endl << endl;
    char typeChoice;       //Zmienna przetrzymująca wybór dotyczący typu danych w tablicy
    while (true) {
        cout << "Wybierz typ danych do sortowania" << endl;
        cout << "1. Integer" << endl;
        cout << "2. Float" << endl;
        cin >> typeChoice;
        if (typeChoice == '1') {    //Typ danych Integer w tablicy
            App<int> app;       //Jeśli typ danych to int to utwórz obiekt App, który będzie używał tablice int w programie, oraz wszystkie metody będą działać na tym typie danych
            app.type = 'i';     //Zapisz wybór typu danych
            app.run();          //Wywołaj metodę, która włącza program
            break;
        } else if (typeChoice == '2') {     //Typ danych Float w tablicy
            App<float> app;     //Obiekt app będzie używał metody przystosowane do tablic float w programie
            app.type = 'f'; //Zapisz wybór typu danych
            app.run();      //Włącz program
            break;
        }
        else cout << "Niepoprawny wybor!" << endl;
    }

    return 0;
}
