#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <unordered_set>
#include "common.h"

using namespace std;

namespace bb12
{

const int UNORDERED_SET_SIZE = 1000000;
const int RANGE = 100000;

void test_unordered_set() {
    cout << "test_unordered_set()......" << endl;
    unordered_set<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < UNORDERED_SET_SIZE; ++i) {
        try {
            c.insert(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "unordered_set.max_size() = : " << c.max_size() << endl;
    cout << "unordered_set.size() = : " << c.size() << endl;
    cout << "unordered_set.bucket_count() = : " << c.bucket_count() << endl;
    cout << "unordered_set.max_bucket_count() = : " << c.max_bucket_count() << endl;
    cout << "unordered_set.load_factor() = : " << c.load_factor() << endl;
    cout << "unordered_set.max_load_factor() = : " << c.max_load_factor() << endl;

    for (int i = 0; i < 20; ++i) {
        cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements" << endl;
    }

    timeStart = clock();
    auto it = find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    auto pItem = c.find(target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (pItem != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}