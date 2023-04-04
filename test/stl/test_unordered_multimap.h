#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

namespace bb09
{

const int UNORDERED_MULTIMAP_SIZE = 1000000;
const int RANGE = 100000;

void test_unordered_multimap() {
    cout << "test_unordered_multimap()......" << endl;
    unordered_multimap<int, int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < UNORDERED_MULTIMAP_SIZE; ++i) {
        try {
            c.insert(pair<int, int>(i, rand() % RANGE));
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "unordered_multimap.max_size() = " << c.max_size() << endl;
    cout << "unordered_multimap.size() = " << c.size() << endl;

    timeStart = clock();
    auto it = c.find(target);
    cout << "calling unordered_multimap.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}