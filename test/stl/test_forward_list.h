#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <forward_list>

using namespace std;

namespace bb04
{

const int FORWARD_LIST_SIZE = 1000000;
const int RANGE = 100000;

void test_forward_list() {
    cout << "test_forward_list()......" << endl;
    forward_list<int> c;
    clock_t timeStart = clock();
    for (long i = 0; i < FORWARD_LIST_SIZE; ++i) {
        try {
            c.push_front(rand() % RANGE);
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "forward_list.max_size() = : " << c.max_size() << endl;
    cout << "forward_list.front() = " << c.front() << endl;

    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (*pItem == target) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    c.sort();
    cout << "calling forward_list.sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "forward_list.front() = " << c.front() << endl << endl;
    c.clear();
}

}