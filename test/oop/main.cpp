#include "iostream"
#include "complex.h"
#include "string.h"
#include "relation.h"

using namespace std;

void test_complex() {
    Complex c1(1, 2), c2(2, 3);
    cout << c1 << " " << c2 << endl;
    cout << c1 + c2 << " " << c1 + 2 << " " << 3 + c2 << endl;
}

void test_string() {
    String str1("hello"), str2("world");
    String str3(str1), str4 = str2; 
    cout << str3 << " " << str4 << endl;
}

void test_relation() {
    
    {
        cout << "enter..." << endl;
        Base base;
        cout << "exit..." << endl;
    }

}

int main() {
    // test_complex();
    // test_string();
    test_relation();
}