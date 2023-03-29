#ifndef __POLY__
#define __POLY__

#include <iostream>

using namespace std;
namespace poly
{

void haha() { cout << "haha from namespace poly" << endl; }

class A
{
public:
    virtual void intro() { cout << "this is A" << endl; }
    virtual ~A() { cout << "dtor A" << endl; }
};

class B : public A
{
public:
    void intro() { cout << "this is B" << endl; }
    ~B() { cout << "dtor B" << endl; }
};

}

#endif  // __POLY__