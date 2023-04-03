#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>

using namespace std;

namespace bb07
{

const int MULTIMAP_SIZE = 1000000;
const int RANGE = 100000;

void test_multimap() {
    cout << "test_multimap()......" << endl;
    multimap<int, int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < MULTIMAP_SIZE; ++i) {
        try {
            // [] operator is not available for multimap
            //c.insert();
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
}

}