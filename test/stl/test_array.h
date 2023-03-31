#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <array>
#include "common.h"

using namespace std;

const int ARRAY_SIZE = 1000000;
const int RANGE = 100000;
namespace bb01
{

void test_array() {
    cout << "test_array()......" << endl;
    array<int, ARRAY_SIZE> c;
    clock_t timeStart = clock();
    
    for (long i = 0; i < ARRAY_SIZE; ++i) { c[i] = rand() % RANGE; }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "array.data() = " << c.data() << endl;
    cout << "array.size() = : " << c.size() << endl;
    cout << "array.front() = " << c.front() << endl;
    cout << "array.back() = " << c.back() << endl;

    timeStart = clock();
    // sort(c.begin(), c.end());
    ::qsort(c.data(), ARRAY_SIZE, sizeof(int), compareInt);
    cout << "calling ::qsort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "array.front() = " << c.front() << endl;
    cout << "array.back() = " << c.back() << endl;

    timeStart = clock();
    auto pItem = (int*)::bsearch(&target, c.data(), ARRAY_SIZE, sizeof(int), compareInt);
    cout << "calling ::bsearch...\nmilli-seconds : " << clock() - timeStart << endl;
    if (pItem != nullptr) {
        cout << "FOUND " << *pItem << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
}

}