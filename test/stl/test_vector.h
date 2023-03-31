#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

const long VSIZE = 1000000;
namespace bb02
{

void test_vector() {
    cout << "test_vector()......" << endl;
    vector<long> c;
    clock_t timeStart = clock();

    for (long i = 0; i < VSIZE; ++i) {
        try {
            c.push_back(rand());
        } catch(exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "vector.max_size() = : " << c.max_size() << endl;
    cout << "vector.size() = : " << c.size() << endl;
    cout << "vector.capacity() = : " << c.capacity() << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;
    cout << "vector.data() = " << c.data() << endl;

    timeStart = clock();
    sort(c.begin(), c.end());
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl << endl;
    c.clear();
}

}