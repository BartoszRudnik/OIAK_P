#include <algorithm>
#include "QuickSort.h"
using namespace std;

int Partition(int tab[], int p, int r){

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

void QuickSort(int tab[], int p, int r){

    if(p < r){

        int q = Partition(tab, p, r);

        QuickSort(tab, p, q - 1);
        QuickSort(tab, q + 1, r);

    }

}
