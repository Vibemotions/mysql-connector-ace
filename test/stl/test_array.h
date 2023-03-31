#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <array>

using namespace std;

const long ASIZE = 500000L;
namespace bb01
{

void test_array() {
    cout << "test_array()......" << endl;
    array<long, ASIZE> c;
    clock_t timeStart = clock();
    
    for (long i = 0; i < ASIZE; ++i) { c[i] = rand(); }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "array.size() = : " << c.size() << endl;
    cout << "array.front() = " << c.front() << endl;
    cout << "array.back() = " << c.back() << endl;
    cout << "array.data() = " << c.data() << endl;
}

}