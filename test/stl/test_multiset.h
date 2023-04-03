#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <set>

using namespace std;

const long MULTISET_SIZE = 1000000;

namespace bb06
{

void test_multiset() {
    cout << "test_multiset()......" << endl;
    multiset<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i < MULTISET_SIZE; ++i) {
        try {
            c.insert(rand());
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "multiset.max_size() = : " << c.max_size() << endl;
    cout << "multiset.size() = : " << c.size() << endl;

    timeStart = clock();

    auto pItem = find(c.begin(), c.end(), target);
    if (pItem != c.end()) {
        cout << "found " << *pItem << endl;
    } else {
        cout << "not found" << endl;
    }

    // timeStart = clock();
    // auto pItem = find(c.begin(), c.end(), target);
    // if (pItem != c.end()) {
    //     cout << "found " << *pItem << endl;
    // } else {
    //     cout << "not found" << endl;
    // }

    c.clear();
}

}