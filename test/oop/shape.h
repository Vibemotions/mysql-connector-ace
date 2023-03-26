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
    ~Shape() {
        cout << "Shape dtor..." << endl;
    }
    virtual void draw() const = 0;
    virtual void intro();
    int objectID() const { return id; }

private:
    int id;
};

class Square : public Shape
{
    Square() {
        cout  << "Square ctor..." << endl;
    }
    ~Square() {
        cout << "Square dtor..." << endl;
    }
};

class Cycle :public Shape
{
    Cycle() {
        cout  << "Cycle ctor..." << endl;
    }
    ~Cycle() {
        cout << "Cycle dtor..." << endl;
    }
};

#endif  // __SHAPE__