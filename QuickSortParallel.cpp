#include "QuickSortParrallel.h"
#include <algorithm>
#include <thread>
using namespace std;

int PartitionParallel(int tab[], int p, int r){

    int x = tab[r];
    int i = p - 1;

    for(int j = p; j < r; j++){

        if(tab[j] < x){

            i++;
            swap(tab[i],tab[j]);

        }

    }

    swap(tab[i + 1], tab[r]);
    return (i + 1);

}

void QuickSortParallel(int tab[], int p, int r){

    if(p < r){

        int q = PartitionParallel(tab, p, r);

        thread th1(QuickSortParallel, tab, p, q - 1);
        thread th2(QuickSortParallel, tab, q + 1, r);

        th1.join();
        th2.join();

    }

}