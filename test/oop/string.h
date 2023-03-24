#ifndef __STRING__
#define __STRING__

#include<iostream>
#include<cstring>

using namespace std;

class String
{
public:
    String(const char* cstr = 0);
    // class with pointer member should contains Big Three :
    // 1. copy constructor
    // 2. copy assignment
    // 3. destructor
    String(const String& str);
    String& operator = (const String& str);
    ~String();
    char* get_c_str() const { return m_data; };

private:
    char* m_data;
};


// default parameters can be declared either in function
// declaration or in function definition except for both
/*
    eg : error usage
    
    String(const char* cstr = 0);
    String(const char* cstr = 0) {}
*/
inline
String::String(const char* cstr) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::String(const String& str) {
    // private member 'm_data' can be accessed directly
    // because these 2 objects are friends to each other
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline
String& String::operator = (const String& str) {
    // MUST check self-assignment in operator =
    if (this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline
String::~String() {
    delete[] m_data;
}
#endif  // __STRING__

inline
ostream& operator << (ostream& os, const String& str) {
    return os << str.get_c_str();
}