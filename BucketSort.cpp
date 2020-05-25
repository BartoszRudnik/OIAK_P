#include <queue>
using namespace std;

int wstawianie(int* tab, int size) {

    for (int j = 1; j < size; j++) {

        int klucz = tab[j];
        int i = j - 1;
        while (i >= 0 && tab[i] > klucz) {

            tab[i + 1] = tab[i];
            i--;

        }
        tab[i + 1] = klucz;

    }

    return *tab;

}

int kubelkowe(int* tab, int size) {

    queue<int> kubelki[1000];
    int pomoc = 0;

    for (int i = 0; i < size; i++) {

        int index = size * tab[i];
        kubelki[index].push(tab[i]);

    }

    for (int i = 0; i < size - 1; i++) {

        wstawianie(tab, size);

    }


    for (int i = 0; i < size; i++) {

        for (int j = 0; j < kubelki[i].size(); j++) {
            tab[pomoc] = kubelki->front();
            kubelki->pop();
            pomoc ++;
        }

    }

    return *tab;

}
