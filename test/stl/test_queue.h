#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>

using namespace std;

namespace bb15
{

const int QUEUE_SIZE = 1000000;
const int RANGE = 100000;

void test_queue() {
    cout << "test_queue()......" << endl;
    queue<int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < QUEUE_SIZE; ++i) {
        try {
            c.push(rand() % RANGE);
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "queue.size() = " << c.size() << endl;
    cout << "queue.front() = " << c.front() << endl;
    cout << "queue.bakc()" << c.back() << endl;
    c.pop();
    cout << "queue.size() = " << c.size() << endl;
    cout << "queue.front() = " << c.front() << endl;
    cout << "queue.back()" << c.back() << endl;

    queue<int, list<int>> c1;
    queue<int, vector<int>> c2;
    cout << endl;
}

}