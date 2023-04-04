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

namespace bb08
{

const int UNORDERED_MULTISET_SIZE = 1000000;
const int RANGE = 100000;

void test_unordered_multiset() {
    cout << "test_unordered_multiset()......" << endl;
    unordered_set<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < UNORDERED_MULTISET_SIZE; ++i) {
        try {
            c.insert(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "unordered_multiset.max_size() = : " << c.max_size() << endl;
    cout << "unordered_multiset.size() = : " << c.size() << endl;
    cout << "unordered_multiset.bucket_count() = : " << c.bucket_count() << endl;
    cout << "unordered_multiset.max_bucket_count() = : " << c.max_bucket_count() << endl;
    cout << "unordered_multiset.load_factor() = : " << c.load_factor() << endl;
    cout << "unordered_multiset.max_load_factor() = : " << c.max_load_factor() << endl;

    for (int i = 0; i < 20; ++i) {
        cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements" << endl;
    }

    timeStart = clock();
    auto it = find(c.begin(), c.end(), target);
    cout << "calling unordered_multiset.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    auto pItem = c.find(target);
    cout << "calling unordered_multiset.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (pItem != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}