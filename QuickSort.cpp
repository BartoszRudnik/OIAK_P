#include <algorithm>
#include <vector>
#include "QuickSort.h"
using namespace std;

int Partition(vector <int> vec, int p, int r);

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

void QuickSortV(vector<int> vec, int p, int r){

    if(p < r){

        int q = Partition(vec, p, r);

        QuickSortV(vec, p, q - 1);
        QuickSortV(vec, q + 1, r);

    }

}

int Partition(vector <int> vec, int p, int r){

    int x = vec[r];
    int i = p - 1;

    for(int j = p; j < r; j++){

        if(vec[j] < x){

            i++;
            swap(vec[i],vec[j]);

        }

    }

    swap(vec[i + 1], vec[r]);
    return (i + 1);

}
