#ifndef __RELATION__
#define __RELATION__

#include <iostream>

using namespace std;

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

class Component {
public:
    Component() {
        cout << "Component ctor..." << endl;
    }
    ~Component() {
        cout << "Component dtor..." << endl;
    }
    void intro() { cout << "This is Component..." << endl; }
    
    int id;
private:

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
    void intro() {
        cout << "calling Component's function...";
        // Derived 'has-a' Component, then
        // it can call Component's functions
        c.intro();
    }
    int id;

private:
    Component c;
};

#endif  // __RELATION__