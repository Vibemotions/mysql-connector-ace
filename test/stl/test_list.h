#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;

namespace bb03
{

const int LIST_SIZE = 1000000;
const int RANGE = 100000;

void test_list() {
    cout << "test_list()......" << endl;
    list<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < LIST_SIZE; ++i) {
        try {
            c.push_back(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "list.max_size() = : " << c.max_size() << endl;
    cout << "list.size() = : " << c.size() << endl;
    cout << "list.front() = " << c.front() << endl;
    cout << "list.back() = " << c.back() << endl;

    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (*pItem == target) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    // global method ::sort() is not available for list
    c.sort();
    cout << "calling list.sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "list.front() = " << c.front() << endl;
    cout << "list.back() = " << c.back() << endl << endl;
    c.clear();
}

}