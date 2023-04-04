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

namespace bb11
{

const int MAP_SIZE = 1000000;
const int RANGE = 100000;

void test_map() {
    cout << "test_map()......" << endl;
    map<int, int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < MAP_SIZE; ++i) {
        try {
            c[i] = rand() % RANGE;
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "map.max_size() = : " << c.max_size() << endl;
    cout << "map.size() = : " << c.size() << endl;
    
    timeStart = clock();
    auto it = c.find(target);
    cout << "calling map.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}