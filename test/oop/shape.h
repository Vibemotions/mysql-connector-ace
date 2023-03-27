#ifndef __SHAPE__
#define __SHAPE__

#include <iostream>

using namespace std;

class Shape
{
public:
    Shape() {
        cout  << "Shape ctor..." << endl;
    }
    virtual ~Shape() {
        cout << "Shape dtor..." << endl;
    }
    virtual void draw() const = 0;
    virtual void intro() {}
};

class Square : public Shape
{
public:
    Square() {
        cout  << "Square ctor..." << endl;
    }
    ~Square() {
        cout << "Square dtor..." << endl;
    }
    void draw() const {}
    void intro() {}
};

#endif  // __SHAPE__