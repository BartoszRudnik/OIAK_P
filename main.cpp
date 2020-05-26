#include <iostream>
#include "testy.h"
using namespace std;

int main() {

    int n, nrAlg;
    bool spr = true;

    cout << "Podaj liczbe danych do posortowania: ";
    cin >> n;

    while(spr){

        cout << "Wybierz wersje algorytmu: " << endl;
        cout << "1. Wersja jednowatkowa" << endl;
        cout << "2. Wersja wielowatkowa (bez ograniczen liczby watkow)" << endl;
        cout << "3. Wersja wielowatkowa (mozliwosc wyboru maksymalnej liczby watkow)" << endl;
        cout << "0. Wyjscie" << endl;

        cin >> nrAlg;

        switch(nrAlg){

            case 0:
                spr = false;
                break;
            case 1:
                testSingleThread(n);
                break;
            case 2:
                testNoLimit(n);
                break;
            case 3:
                testLimit(n);
                break;
            default:
                cout << "Wybrano zly numer" << endl;
                break;

        }

    }

    return 0;

}
