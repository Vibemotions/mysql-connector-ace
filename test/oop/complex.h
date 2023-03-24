#ifndef __COMPLEX__
#define __COMPLEX__

#include<iostream>

using namespace std;
class Complex
{
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    // 1. keyword 'const' used in member function indicates
    // that the function does not mean to write member data
    // 2. functions defined within the class body are going
    // to be candidates of inline function automatically
    double real() const { return re; }
    double imag() const { return im; }
    Complex& operator += (const Complex&);

private:
    double re, im;
    // 1. friend is available to access private member of the class
    // 2. ojbects initialized from the same class are friends mutually
    friend Complex& __doapl(Complex*, const Complex&);
};

inline double real(const Complex& x) { return x.real(); }
inline double imag(const Complex& x) { return x.imag(); }

inline
ostream& operator << (ostream& os, const Complex& x) {
    return os << "(" << real(x) << "," << imag(x) << ")";
};

inline
Complex operator + (const Complex& x, const Complex& y) {
    // cannot return by reference because usage
    // typename() will generate local object
    return Complex(real(x) + real(y), imag(x) + imag(y));
}

inline
Complex operator + (const Complex& x, double y) {
    return Complex(real(x) + y, imag(x));
}

inline
Complex operator + (double x, const Complex& y) {
    return Complex(x + real(y), imag(y));
}

inline
Complex& Complex::operator+=(const Complex& x) {
    // eg : c1 += c2;
    // pass 'c1' as this pointer explicitly
    // pass 'c2' as reference
    return __doapl(this, x);
}

inline
Complex& __doapl(Complex* ptr, const Complex& x) {
    ptr->re += x.re;
    ptr->im += x.im;
    return *ptr;
}

#endif  // __COMPLEX__