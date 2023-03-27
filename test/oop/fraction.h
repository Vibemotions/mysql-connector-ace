#ifndef __FRACTION__
#define __FRACTION__

class Fraction
{
public:
    // convert other type to this class
    Fraction(int num, int den = 1) :
        m_numerator(num), m_denominator(den)
    {}
    // convert this class to other type
    operator double() const {
        return (double)(m_numerator / m_denominator);
    }

private:
    int m_numerator;
    int m_denominator;
};

#endif  // __FRACTION__