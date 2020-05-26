#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>
#include "QuickSort.h"
#include "QuickSortOptimal.h"
#include "QuickSortParrallel.h"
using namespace std;
using namespace std::chrono;

const int tests = 100;

bool mojaNazwa(int *pInt, int n);

void saveFile(string nazwa, double * result){

    ofstream output(nazwa);

    for(int i = 0; i < tests; i++){
        output << result[i] << endl;
    }

    output.close();

}

void testSingleThread(int n){

    auto * result = new double[tests];

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        QuickSort(tab, 0, n - 1);
        auto finish = high_resolution_clock::now();

        if(mojaNazwa(tab, n))
            cout << "OK" << endl;
        else
            cout << "Zle" << endl;

        duration<double> time = finish - start;
        time *= 1000000;

        result[t] = time.count();

        delete[] tab;

    }

    saveFile("SingleThread.txt", result);

    delete [] result;

}

void testNoLimit(int n){

    auto * result = new double[tests];

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        QuickSortParallel(tab, 0, n - 1);
        auto finish = high_resolution_clock::now();

        if(mojaNazwa(tab, n))
            cout << "OK" << endl;
        else
            cout << "Zle" << endl;

        duration<double> time = finish - start;
        time *= 1000000;

        result[t] = time.count();

        delete[] tab;

    }

    saveFile("NoLimitThread.txt", result);

    delete [] result;

}

void testLimit(int n){

    int tNum;

    cout << "Podaj maksymalna liczbe watkow: ";
    cin >> tNum;

    auto * result = new double[tests];

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        QuickSortOptimal(tab, 0, n - 1, tNum);
        auto finish = high_resolution_clock::now();

        if(mojaNazwa(tab, n))
            cout << "OK" << endl;
        else
            cout << "Zle" << endl;

        duration<double> time = finish - start;
        time *= 1000000;

        result[t] = time.count();

        delete[] tab;

    }

    saveFile("LimitThread.txt", result);

    delete [] result;

}

bool mojaNazwa(int *pInt, int n) {

    for(int i = 1; i < n; i++){

        if(pInt[i] < pInt[i - 1])
            return false;

    }

    return true;

}





