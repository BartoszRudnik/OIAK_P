#include <iostream>
#include "testy.h"
using namespace std;

int main() {

    int n;

    cout << "Podaj liczbe danych do posortowania: ";
    cin >> n;

    testSingleThread(n);
    testNoLimit(n);
    testLimit(n);

    return 0;

}
