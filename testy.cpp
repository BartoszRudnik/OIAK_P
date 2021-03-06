#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>
#include "QuickSort.h"
#include "QuickSortOptimal.h"
#include "QuickSortParrallel.h"
#include "BubbleSort.h"
#include "BucketParallel.h"
#include "BubbleSortParallel.h"
#include "BucketSort.h"

using namespace std;
using namespace std::chrono;

const int tests = 250;

bool isSorted(int *pInt, int n);
double average(double *tab);

void saveFile(string nazwa, double result){

    ofstream output(nazwa, std::ios::app);

    output << result << endl;

    output.close();

}

void testBucketSingle(int n){

    auto * result = new double[tests];

    int pom = 0;

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % 4000 + 1;
        }

        auto start = high_resolution_clock::now();
        tab = BucketSingleThread(tab, n);
        auto finish = high_resolution_clock::now();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTBucketSingleThread.txt", r);

    delete [] result;

}

void testBucketParallel(int n) {

    auto *result = new double[tests];
    int tNum = 8;
    int pom = 0;

    unsigned int supporteThreadsAmount = std::thread::hardware_concurrency();
    std::cout << "Twój system obsługuje " << supporteThreadsAmount << " wątków.\n";

    bool tNumOk = false;

    while (!tNumOk) {
        cout << "Podaj maksymalna liczbe watkow(2, 4, 6 lub 8): ";
        cin >> tNum;

        if(tNum == 2 || tNum == 4 || tNum == 6 || tNum == 8){
            tNumOk = true;
        }
    }

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % 4000 + 1;
        }

        auto start = high_resolution_clock::now();
        tab = BucketParallel(tab,n,tNum);
        auto finish = high_resolution_clock::now();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTBucketThread" + to_string(tNum) + ".txt", r);

    delete [] result;

}

void testQuickSingleThread(int n){

    auto * result = new double[tests];

    int pom = 0;

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        QuickSort(tab, 0, n - 1);
        auto finish = high_resolution_clock::now();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTQuickSingleThread.txt", r);

    delete [] result;

}

void testQuickNoLimit(int n){

    auto * result = new double[tests];

    int pom = 0;

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        QuickSortParallel(tab, 0, n - 1);
        auto finish = high_resolution_clock::now();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTQuickNoLimit.txt",r);

    delete [] result;

}

void testQuickLimit(int n){

    int tNum;
    int pom = 0;

    unsigned int supporteThreadsAmount = std::thread::hardware_concurrency();
    std::cout << "Twój system obsługuje "<< supporteThreadsAmount << " wątków.\n";

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

        setActual();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTQuickLimitThread" + to_string(tNum) + ".txt", r);

    delete [] result;

}

void testBubbleSingleThread(int n){

    auto * result = new double[tests];

    int pom = 0;

    for(int t = 0; t < tests; t++) {

        int *tab = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            tab[i] = rand() % n + 1;
        }

        auto start = high_resolution_clock::now();
        BubbleSort(tab, n);
        auto finish = high_resolution_clock::now();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl;
    else
        cout << "W sortowaniu wystapil blad" << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTBubbleSingleThread.txt", r);

    delete [] result;


}

void testBubbleParalle(int n){

    int tNum;
    int pom = 0;

    unsigned int supporteThreadsAmount = std::thread::hardware_concurrency();
    std::cout << "Twój system obsługuje "<< supporteThreadsAmount << " wątków.\n";

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
        BubbleSortParallel(tab, n, tNum);
        auto finish = high_resolution_clock::now();

        setActualBubble();

        if(isSorted(tab, n))
            pom++;

        duration<double> time = finish - start;

        result[t] = time.count();

        delete[] tab;

    }

    if(pom == tests)
        cout << "Dane zostaly poprawnie posortowane" << endl << endl;
    else
        cout << "W sortowaniu wystapilo: " << tests - pom << " bledow" << endl << endl;

    double r = average(result);
    r *= 1000000;

    saveFile("TESTBubbleThread" + to_string(tNum) + ".txt", r);

    delete [] result;

}

bool isSorted(int *pInt, int n) {

    for(int i = 1; i < n; i++){

        if(pInt[i] < pInt[i - 1])
            return false;

    }

    return true;

}

double average(double * tab){

    double result = 0;

    for(int i = 0; i < tests; i++){

        result += tab[i];

    }

    result /= tests;

    return result;

}





