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
        cout << "1. Quick Sort - Wersja jednowatkowa" << endl;
        cout << "2. Quick Sort - Wersja wielowatkowa (bez ograniczen liczby watkow)" << endl;
        cout << "3. Quick Sort - Wersja wielowatkowa (mozliwosc wyboru maksymalnej liczby watkow)" << endl;
        cout << "4. Bubble Sort - Wersja jednowatkowa" << endl;
        cout << "5. Bubble Sort - Wersja wielowatkowa" << endl;
        cout << "0. Wyjscie" << endl;

        cin >> nrAlg;

        switch(nrAlg){

            case 0:
                spr = false;
                break;
            case 1:
                testQuickSingleThread(n);
                break;
            case 2:
                testQuickNoLimit(n);
                break;
            case 3:
                testQuickLimit(n);
                break;
            case 4:
                testBubbleSingleThread(n);
                break;
            default:
                cout << "Wybrano zly numer" << endl;
                break;

        }

    }

    return 0;

}
