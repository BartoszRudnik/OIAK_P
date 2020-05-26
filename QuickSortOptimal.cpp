#include <thread>
#include "QuickSort.h"

using namespace std;

int actual = 1;

void QuickSortOptimal(int tab[], int p, int r, int maxNum){

    if(p < r){

        int q = Partition(tab, p, r);

        if(actual >= maxNum) {

            QuickSort(tab, p, q - 1);
            QuickSort(tab, q + 1, r);

        }
        else if((actual + 2) <= maxNum){

            actual += 2;
            thread t1(QuickSortOptimal, tab, p, q - 1, maxNum);
            thread t2(QuickSortOptimal, tab, q + 1, r, maxNum);

            t1.join();
            actual--;
            t2.join();
            actual--;

        }
        else if((actual + 1) == maxNum){

            actual++;
            thread t1(QuickSortOptimal, tab, p, q - 1, maxNum);
            QuickSort(tab, q + 1, r);

            t1.join();
            actual--;

        }

    }

}