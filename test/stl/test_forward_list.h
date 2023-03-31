#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <forward_list>

using namespace std;

const long FSIZE = 1000000;
namespace bb04
{

void test_forward_list() {
    cout << "test_forward_list()......" << endl;
    forward_list<int> c;
    clock_t timeStart = clock();
    for (long i = 0; i < FSIZE; ++i) {
        try {
            c.push_front(rand());
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "forward_list.max_size() = : " << c.max_size() << endl;
    cout << "forward_list.front() = " << c.front() << endl;

    timeStart = clock();
    c.sort();
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "forward_list.front() = " << c.front() << endl << endl;
    c.clear();
}

}