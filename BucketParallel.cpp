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
    auto* threads = new vector<thread>[threadNum];

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

    for(int i = 0; i < threadNum; i++){

        thread th(sortBucket, std::ref(bucket[i]));
        threads->push_back(move(th));

    }

    for(int i = 0; i < threadNum; i++){
        threads->at(i).join();
    }

    delete [] threads;

    data = new int[n];
    int tmp = 0;

    for(int i = 0; i < threadNum; i++){

        for(int j = 0; j < bucket[i].size(); j++){

            data[tmp] = bucket[i][j];
            tmp ++;

        }

    }

    delete [] bucket;

    return data;

}