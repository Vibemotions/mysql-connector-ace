#ifndef __RELATION__
#define __RELATION__

#include <iostream>

using namespace std;

class Component;

class Base
{
public:
    Base() {
        cout << "Base ctor..." << endl;
    }
    ~Base() {
        cout << "Base dtor..." << endl;
    }

private:
    ;
};

class Derived : public Base
{
public:
    Derived() {
        cout << "Derived ctor..." << endl;
    }
    ~Derived() {
        cout << "Derived dtor..." << endl;
    }

private:
};

class Component {
public:
    Component() {
        cout << "Component ctor..." << endl;
    }
    ~Component() {
        cout << "Component dtor..." << endl;
    }

private:
    ;
};

#endif  // __RELATION__