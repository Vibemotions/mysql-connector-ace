#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <set>

using namespace std;

namespace bb06
{

const int MULTISET_SIZE = 1000000;
const int RANGE = 100000;

void test_multiset() {
    cout << "test_multiset()......" << endl;
    multiset<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < MULTISET_SIZE; ++i) {
        try {
            c.insert(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "multiset.max_size() = : " << c.max_size() << endl;
    cout << "multiset.size() = : " << c.size() << endl;

    timeStart = clock();
    auto it = ::find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "found " << target << endl;
    } else {
        cout << "not found" << endl;
    }

    timeStart = clock();
    auto pItem = c.find(target);
    cout << "calling multiset.find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (*pItem == target) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    cout << endl;
    c.clear();
}

}