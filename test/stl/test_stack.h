#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>

using namespace std;

namespace bb14
{

const int STACK_SIZE = 1000000;
const int RANGE = 100000;

void test_stack() {
    cout << "test_stack()......" << endl;
    stack<int> c;
    clock_t timeStart = clock();

    for (int i = 0; i < STACK_SIZE; ++i) {
        try {
            c.push(rand() % RANGE);
        } catch (exception& e) {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << clock() - timeStart << endl;
    cout << "stack.size() = " << c.size() << endl;
    cout << "stack.top() = " << c.top() << endl;
    c.pop();
    cout << "stack.size() = " << c.size() << endl;
    cout << "stack.top() = " << c.top() << endl;

    stack<int, list<int>> c1;
    stack<int, vector<int>> c2;

    cout << endl;
}

}