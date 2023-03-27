#ifndef __VPTR__
#define __VPTR__

class A
{
public:
    virtual void vfunc1() {};
    virtual void vfunc2() {};
    void func1();
    void func2();

private:
    int data1, data2;
};

class B : public A
{
public:
    virtual void vfunc1() {};
    void func2();

private:
    int data3;
};

class C : public B
{
public:
    virtual void vfunc1() {};
    void func2();

private:
    int data1, data4;
};

#endif  // __VPTR__