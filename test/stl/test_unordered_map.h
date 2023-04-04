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

namespace bb13
{

const int UNORDERED_MAP_SIZE = 1000000;
const int RANGE = 100000;

void test_unordered_map() {
    cout << "test_unordered_map()......" << endl;
    unordered_map<int, int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < UNORDERED_MAP_SIZE; ++i) {
        try {
            c.insert(pair<int, int>(i, rand() % RANGE));
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "unordered_map.max_size() = " << c.max_size() << endl;
    cout << "unordered_map.size() = " << c.size() << endl;

    timeStart = clock();
    auto it = c.find(target);
    cout << "calling unordered_map.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}