#include <algorithm>
#include <thread>
#include <iostream>

using namespace std;

int actual = 1;
int maxNum = std::thread::hardware_concurrency();

int PartitionOptimal(int tab[], int p, int r){

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

void QuickSortP(int tab[], int p, int r){

    if(p < r){

        int q = PartitionOptimal(tab, p, r);

        QuickSortP(tab, p, q - 1);
        QuickSortP(tab, q + 1, r);

    }

}

void QuickSortOptimal(int tab[], int p, int r){

    if(p < r){

        int q = PartitionOptimal(tab, p, r);

        if(actual >= maxNum) {

            QuickSortP(tab, p, q - 1);
            QuickSortP(tab, q + 1, r);

        }
        else if((actual + 2) <= maxNum){

            actual += 2;
            thread t1(QuickSortOptimal, tab, p, q - 1);
            thread t2(QuickSortOptimal, tab, q + 1, r);

            t1.join();
            actual--;
            t2.join();
            actual--;

        }
        else if((actual + 1) == maxNum){

            actual++;
            thread t1(QuickSortOptimal, tab, p, q - 1);
            QuickSortP(tab, q + 1, r);

            t1.join();
            actual--;

        }

    }

}