#include <iostream>
#include "empty.h"
#include <vector>
#include <algorithm>
#include "../oop/complex.h"
#include "../oop/string.h"
#include "mystring.h"
#include <memory>

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

    vector<int, allocator<int>> vi {5, 28, 50, 83, 70, 590, 245, 59, 24};
    int x = 30, y = 100;
    vi.erase(remove_if(vi.begin(),
                       vi.end(),
                       [x,y](int n){return n < x || y < n;}),
            vi.end());
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
}

void test_Rvalue() {
    int a = 1, b = 2;
    Complex c1(1, 2), c2(2, 3);
    String s1("hello"), s2("world");
    // a + b = 3;           error
    c1 + c2 = Complex();
    s1 + s2 = String();
    // int() = int(666);    error
    Complex() = Complex(5, 6);
    String() = "lvalue required as left operand of assignment";
}

void test_move() {
    ;
}

int main() {
    // test_empty();
    // test_detection();
    // test_lambda();
    // test_Rvalue();
    // test_move();
}
