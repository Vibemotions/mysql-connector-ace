#include "iostream"
#include "complex.h"
#include "string.h"
#include "account.h"
#include "relation.h"
#include "virtual.h"

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

Complex c3(1, 2);   // 1. global object, can be regarded as static object
void test_lifetime() {

    {
        static Complex c2(1, 2);    // 2. static object
        Complex* p = new Complex;   // 3. heap object
        // it can cause memory leak without the line below, because
        // when scope finished, heap object exists still while the
        // pointer 'p' will be recycled
        delete p;
        Complex c1(1, 2);           // 4. stack object, also as auto object
    }
}

void test_static() {
    Account a;
    // 2 ways to call static member function
    cout << "rate = " << Account::m_rate << endl;
    a.set_rate(5.0);            // 1. object
    cout << "rate = " << Account::m_rate << endl;
    Account::set_rate(7.0);     // 2. class name
    cout << "rate = " << Account::m_rate << endl;
}

void test_relation() {
    Base b;
    Component c;
    Derived d;
    cout << sizeof(b) << " " << sizeof(c) << " " << sizeof(d) << endl;
    d.intro();
}

void test_virtual() {
    ;
}

int main() {
    // test_complex();
    // test_string();
    // test_lifetime();
    // test_static();
    // test_relation();
    test_virtual();
}