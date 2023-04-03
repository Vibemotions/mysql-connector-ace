#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

namespace bb02
{

const int VECTOR_SIZE = 1000000;
const int RANGE = 100000;

void test_vector() {
    cout << "test_vector()......" << endl;
    vector<int> c;
    clock_t timeStart = clock();

    for (long i = 0; i < VECTOR_SIZE; ++i) {
        try {
            c.push_back(rand() % RANGE);
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
    auto it = ::find(c.begin(), c.end(), target);
    cout << "calling ::find...\nmilli-seconds : " << clock() - timeStart << endl;
    if (it != c.end()) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    timeStart = clock();
    sort(c.begin(), c.end());
    cout << "calling sort...\nmilli-seconds : " << clock() - timeStart << endl;
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;

    timeStart = clock();
    int* pItem = (int*)::bsearch(&target, c.data(), c.size(), sizeof(int), compareInt);
    cout << "calling ::bsearch...\nmilli-seconds : " << clock() - timeStart << endl;
    if (pItem != nullptr) {
        cout << "FOUND " << target << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

    c.clear();
}

}