#include <algorithm>
#include "BubbleSort.h"

using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int BubbleSort(int tab[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
}

