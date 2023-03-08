#ifndef _SQL_STRING_H_
#define _SQL_STRING_H_

#include <string>
#include <algorithm>
#include <iostream>

class SQLString {

    std::string realStr;

public:
    ~SQLString() {}

    SQLString() {}
    
    SQLString(const SQLString& other) : realStr(other.realStr) {}

    SQLString(const std::string& other) : realStr(other) {}

    SQLString(const char other[]) : realStr(other) {}

    SQLString(const char* s, size_t n) : realStr(s, n) {}
};

#endif