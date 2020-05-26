#include "QuickSortParrallel.h"
#include "QuickSort.h"
#include <thread>
using namespace std;

void QuickSortParallel(int tab[], int p, int r){

    if(p < r){

        int q = Partition(tab, p, r);

        thread th1(QuickSortParallel, tab, p, q - 1);
        thread th2(QuickSortParallel, tab, q + 1, r);

        th1.join();
        th2.join();

    }

}