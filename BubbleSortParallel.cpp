#include <thread>
#include "BubbleSortParallel.h"

using namespace std;

int actualBubble = 1;

void setActualBubble(){
    actualBubble = 1;
}

void compare(int tab[], int index, int n)
{
    // Each thread compares
    // two consecutive elements of the array

    if ((tab[index] > tab[index + 1]) && (index + 1 < n)) {
        swap(tab[index], tab[index + 1]);
    }
}

void BubbleSortParallel(int tab[], int tabLength, int maxThreads){
    int i, j, tmp;
    maxThreads = (tabLength + 1) / 2;

    thread threads[maxThreads];

    for (i = 1; i <= tabLength; i++) {
        // Odd step
        if (i % 2 == 1) {
            tmp = 0;

            // Creating threads
            for (j = 0; j < maxThreads; j++) {
                threads[j] = thread(compare, tab, tmp, tabLength);
                tmp = tmp + 2;
            }

            // joining threads i.e. waiting
            // for all the threads to complete
            for (j = 0; j < maxThreads; j++)
                threads[j].join();
        }

            // Even step
        else {
            tmp = 1;

            // Creating threads
            for (j = 0; j < maxThreads - 1; j++){
                threads[j] = thread(compare, tab, tmp, tabLength);
                tmp = tmp + 2;
            }

            // joining threads i.e. waiting
            // for all the threads to complete
            for (j = 0; j < maxThreads - 1; j++)
                threads[j].join();
        }
    }
}