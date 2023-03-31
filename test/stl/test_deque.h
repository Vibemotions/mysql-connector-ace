#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <deque>

using namespace std;

const long DSIZE = 1000000;

namespace bb05
{

void test_deque() {
    cout << "test_deque()......" << endl;
    deque<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i < DSIZE; ++i) {
        try {
            c.push_back(rand());
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
    sort(c.begin(), c.end());
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "deque.front() = " << c.front() << endl;
    cout << "deque.back() = " << c.back() << endl << endl;
    c.clear();
}

}