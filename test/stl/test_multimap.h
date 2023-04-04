#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "common.h"

using namespace std;

namespace bb07
{

const int MULTIMAP_SIZE = 1000000;
const int RANGE = 100000;

void test_multimap() {
    cout << "test_multimap()......" << endl;
    multimap<int, int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < MULTIMAP_SIZE; ++i) {
        try {
            // [] operator is not available for multimap
            c.insert(pair<int, int>(i, rand() % RANGE));
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "multimap.maxsize() = " << c.max_size() << endl;
    cout << "multimap.size() = " << c.size() << endl;

    timeStart = clock();
    auto it = c.find(target);
    cout << "calling find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}