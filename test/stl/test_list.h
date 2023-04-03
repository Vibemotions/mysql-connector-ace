#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;

const long LIST_SIZE = 1000000;

namespace bb03
{

void test_list() {
    cout << "test_list()......" << endl;
    list<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i < LIST_SIZE; ++i) {
        try {
            c.push_back(rand());
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
    c.sort();
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "list.front() = " << c.front() << endl;
    cout << "list.back() = " << c.back() << endl << endl;
    c.clear();
}

}