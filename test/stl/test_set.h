#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <set>
#include "common.h"

using namespace std;

namespace bb10
{

const int SET_SIZE = 1000000;
const int RANGE = 100000;

void test_set() {
    cout << "test_set()......" << endl;
    set<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < SET_SIZE; ++i) {
        try {
            c.insert(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "set.max_size() = : " << c.max_size() << endl;
    cout << "set.size() = : " << c.size() << endl;

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
    cout << "calling set.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (pItem != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}
