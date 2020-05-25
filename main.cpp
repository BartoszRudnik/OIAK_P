#include <iostream>
#include "QuickSort.h"
#include "QuickSortParrallel.h"
using namespace std;

int main() {

    int tab[5];

    for(int i = 0; i < 5; i++){
        cin >> tab[i];
    }

    QuickSortParallel(tab,0,4);

    for(int i = 0; i < 5; i++){
        cout << tab[i] << " ";
    }

    return 0;

}
