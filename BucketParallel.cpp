#include <vector>
#include <algorithm>
#include <iostream>
#include <thread>
#include "QuickSort.h"
using namespace std;

void sortBucket(vector<int>& vec){

    sort(vec.begin(),vec.end());

}

int* BucketParallel(int* data,int n, int threadNum){

    auto* bucket = new vector<int>[threadNum];

    for(int i = 0; i < n; i++){

        if(data[i] < 500)
            bucket[0].push_back(data[i]);
        else if(data[i] >= 500 && data[i] < 1000)
            bucket[1].push_back(data[i]);
        else if(data[i] >= 1000 && data[i] < 1500)
            bucket[2].push_back(data[i]);
        else if(data[i] >= 1500 && data[i] < 2000)
            bucket[3].push_back(data[i]);
        else if(data[i] >= 2000 && data[i] < 2500)
            bucket[4].push_back(data[i]);
        else if(data[i] >= 2500 && data[i] < 3000)
            bucket[5].push_back(data[i]);
        else if(data[i] >= 3000 && data[i] < 3500)
            bucket[6].push_back(data[i]);
        else if(data[i] >= 3500 && data[i] <= 4000)
            bucket[7].push_back(data[i]);

    }

    thread t1(sortBucket,std::ref(bucket[0]));
    thread t2(sortBucket,std::ref(bucket[1]));
    thread t3(sortBucket,std::ref(bucket[2]));
    thread t4(sortBucket,std::ref(bucket[3]));
    thread t5(sortBucket,std::ref(bucket[4]));
    thread t6(sortBucket,std::ref(bucket[5]));
    thread t7(sortBucket,std::ref(bucket[6]));
    thread t8(sortBucket,std::ref(bucket[7]));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    data = new int[n];
    int tmp = 0;

    for(int i = 0; i < threadNum; i++){

        for(int j = 0; j < bucket[i].size(); j++){

            data[tmp] = bucket[i][j];
            tmp ++;

        }

    }

    return data;

}