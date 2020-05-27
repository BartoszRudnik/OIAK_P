#include <queue>
#include <algorithm>

using namespace std;

int* BucketSingleThread(int* data, int n) {

    auto* bucket = new vector<int>[8];

    for (int i = 0; i < n; i++) {
        if (data[i] < 500)
            bucket[0].push_back(data[i]);
        else if (data[i] >= 500 && data[i] < 1000)
            bucket[1].push_back(data[i]);
        else if (data[i] >= 1000 && data[i] < 1500)
            bucket[2].push_back(data[i]);
        else if (data[i] >= 1500 && data[i] < 2000)
            bucket[3].push_back(data[i]);
        else if (data[i] >= 2000 && data[i] < 2500)
            bucket[4].push_back(data[i]);
        else if (data[i] >= 2500 && data[i] < 3000)
            bucket[5].push_back(data[i]);
        else if (data[i] >= 3000 && data[i] < 3500)
            bucket[6].push_back(data[i]);
        else if (data[i] >= 3500 && data[i] <= 4000)
            bucket[7].push_back(data[i]);
    }

    for(int i = 0; i < 8; i++){
        sort(bucket[i].begin(),bucket[i].end());
    }

    int tmp = 0;
    //data = new int[n];

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < bucket[i].size(); j++){

            data[tmp] = bucket[i][j];
            tmp ++;

        }

    }

    delete [] bucket;

    return data;

}
