#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <deque>

using namespace std;

namespace bb05
{

const int DEQUE_SIZE = 1000000;
const int RANGE = 100000;

void test_deque() {
    cout << "test_deque()......" << endl;
    deque<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < DEQUE_SIZE; ++i) {
        try {
            c.push_back(rand() % RANGE);
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "deque.max_size() = : " << c.max_size() << endl;
    cout << "deque.size() = : " << c.size() << endl;
    cout << "deque.front() = " << c.front() << endl;
    cout << "deque.back() = " << c.back() << endl;

    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (*pItem == target) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    sort(c.begin(), c.end());
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "deque.front() = " << c.front() << endl;
    cout << "deque.back() = " << c.back() << endl << endl;
    c.clear();
}

}