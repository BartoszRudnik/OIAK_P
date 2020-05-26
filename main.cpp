#include <iostream>
#include <chrono>
#include <time.h>
#include "QuickSort.h"
#include "QuickSortParrallel.h"
#include "QuickSortOptimal.h"
using namespace std;
using namespace std::chrono;

int main() {

    int n = 1000;

    int tab[n];
    int tab2[n];
    int tab3[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++){

        int num = rand() % n + 1;

        tab[i] = num;
        tab2[i] = num;
        tab3[i] = num;

    }

    auto start = high_resolution_clock::now();
    QuickSortParallel(tab,0,n - 1);
    auto finish = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    QuickSort(tab2,0,n - 1);
    auto finish2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    QuickSortOptimal(tab3,0,n - 1);
    auto finish3 = high_resolution_clock::now();

    for(int i = 0; i < 100; i++){
        cout << tab[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < 100; i++){
        cout << tab2[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < 100; i++){
        cout << tab3[i] << " ";
    }

    cout << endl;

    duration<double> time = finish - start;
    duration<double> time2 = finish2 - start2;
    duration<double> time3 = finish3 - start3;

    time *= 1000000;
    time2 *= 1000000;
    time3 *= 1000000;

    cout << endl <<"Wielowatkowo bez limitu watkow: " <<time.count() << endl <<"Jednowatkowo: " <<time2.count() << endl << "Wielowatkowo z limitem watkow: " << time3.count();

    return 0;

}
