#include "iostream"
#include "complex.h"

using namespace std;

void test_complex() {
    Complex c1(1, 2), c2(2, 3);
    cout << c1 << " " << c2 << endl;
    cout << c1 + c2 << " " << c1 + 2 << " " << 3 + c2 << endl;
}

void test_string() {

}

int main() {
    test_complex();
    test_string();
}