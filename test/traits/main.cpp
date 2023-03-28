#include <iostream>
#include "empty.h"

using namespace std;

void test_empty() {
    Empty e1;
    Empty e2(e1);
    e2 = e1;
}

void test_detection() {
    decltype(666) id;
    cout << sizeof(id) << endl;
}

void test_lambda() {
    int id = 0;
    auto f = [&id]() mutable {
        cout << "id = " << id << endl;
        ++id;
    };
    id = 666;
    f();f();f();
    cout << "id = " << id << endl;
}

int main() {
    // test_empty();
    // test_detection();
    test_lambda();
}