#ifndef _SQL_STRING_H_
#define _SQL_STRING_H_

#include <string>
#include <algorithm>
#include <iostream>

class SQLString {

    std::string realStr;

public:

    static const size_t npos = std::string::npos;

    ~SQLString() {}

    SQLString() {}

    SQLString(const SQLString& other) : realStr(other.realStr) {}

    SQLString(const std::string& other) : realStr(other) {}

    SQLString(const char other[]) : realStr(other) {}

    SQLString(const char* s, size_t n) : realStr(s, n) {}

    const SQLString& operator=(const char* s) {
        realStr = s;
        return *this;
    }

    const SQLString& operator=(const std::string& rhs) {
        realStr = rhs;
        return *this;
    }

    const SQLString& operator=(const SQLString& rhs) {
        realStr = rhs.realStr;
        return *this;
    }

    // Conversion to std::string
    const std::string& operator&() const {
        return realStr;
    }

    // For access std::string methods
    std::string* operator->() {
        return &realStr;
    }

    /*
        In order to use SQLString like std::string, we have a series of func below.
    */

    int compare(const SQLString& str) const {
        return realStr.compare(str.realStr);
    }

    int compare(const char* s) const {
        return realStr.compare(s);
    }

    int compare(size_t pos, size_t n, const char* s) const {
        return realStr.compare(pos, n, s);
    }

    int caseCompare(const SQLString &s) const {
        // std::string tmp(realStr);
        // std::string str(s);
        // std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        // std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        // return tmp.compare(str);
    }

    // Provide a public method for accessing private member variable realStr
    const std::string& asStdString() const {
        return realStr;
    }

    const char* c_str() const {
        return realStr.c_str();
    }

    size_t length() const {
        return realStr.length();
    }

    SQLString& append(const std::string& str) {
        realStr.append(str);
        return *this;
    }

    const char& operator[](size_t pos) const {
        return realStr[pos];
    }

    size_t find(char c, size_t pos = 0) const {
        return realStr.find(c, pos);
    }

    SQLString substr(size_t pos = 0, size_t n = npos) const {
        return realStr.substr(pos, n);
    }

    const SQLString& replace(size_t pos, size_t n, const SQLString& s) {
        realStr.replace(pos, n, s.realStr);
        return *this;
    }

    size_t find_first_of(char c, size_t pos = 0) const {
        return realStr.find_first_of(c, pos);
    }

    size_t find_last_of(char c, size_t pos = 0) const {
        return realStr.find_last_of(c, pos);
    }

    const SQLString& operator+=(const SQLString& op2) {
        realStr += op2.realStr;
        return *this;
    }
};

inline const SQLString operator+(const SQLString& op1, const SQLString& op2) {
    return SQLString(op1.asStdString() + op2.asStdString());
}

inline bool operator==(const SQLString& op1, const SQLString &op2) {
    return (op1.asStdString() == op2.asStdString());
}

inline bool operator!=(const SQLString& op1, const SQLString &op2) {
    return (op1.asStdString() != op2.asStdString());
}

inline bool operator<(const SQLString& op1, const SQLString &op2) {
    return (op1.asStdString() < op2.asStdString());
}

inline std::ostream& operator<<(std::ostream& os, const SQLString& str) {
    return os << str.asStdString();
}

#endif
