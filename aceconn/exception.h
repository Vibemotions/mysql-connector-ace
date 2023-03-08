#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <stdexcept>
#include <string>
#include <memory>

class SQLException : public std::runtime_error {
protected:
    const std::string sql_state;
    const int errNo;

public:
    SQLException(const SQLException &e) : std::runtime_error(e.what()), sql_state(e.sql_state), errNo(e.errNo) {}

    SQLException(const std::string& reason, const std::string& SQLState, int vendorCode) :
        std::runtime_error(reason), sql_state(SQLState), errNo(vendorCode) {}

    SQLException(const std::string& reason, const std::string& SQLState) : std::runtime_error(reason), sql_state(SQLState), errNo(0) {}

    SQLException(const std::string& reason) : std::runtime_error(reason), sql_state("HY000"), errNo(0) {}

    SQLException() : std::runtime_error(""), sql_state("HY000"), errNo(0) {}

    const std::string & getSQLState() const {
        return sql_state;
    }

    const char* getSQLStateCStr() const {
        return sql_state.c_str();
    }

    int getErrorCode() const {
        return errNo;
    }

    virtual ~SQLException() noexcept {};
};

struct MethodNotImplementedException : public SQLException
{
    MethodNotImplementedException(const MethodNotImplementedException& e) : SQLException(e.what(), e.sql_state, e.errNo) {}
    MethodNotImplementedException(const std::string& reason) : SQLException(reason, "", 0) {}
};

struct InvalidArgumentException : public SQLException
{
    InvalidArgumentException(const InvalidArgumentException& e) : SQLException(e.what(), e.sql_state, e.errNo) {}
    InvalidArgumentException(const std::string& reason) : SQLException(reason, "", 0) {}
};

struct InvalidInstanceException : public SQLException
{
    InvalidInstanceException(const InvalidInstanceException& e) : SQLException(e.what(), e.sql_state, e.errNo) {}
    InvalidInstanceException(const std::string& reason) : SQLException(reason, "", 0) {}
};

struct NonScrollableException : public SQLException
{
    NonScrollableException(const NonScrollableException& e) : SQLException(e.what(), e.sql_state, e.errNo) {}
    NonScrollableException(const std::string& reason) : SQLException(reason, "", 0) {}
};

struct SQLUnsupportedOptionException : public SQLException
{
    SQLUnsupportedOptionException(const SQLUnsupportedOptionException& e, const std::string conn_option) :
        SQLException(e.what(), e.sql_state, e.errNo),
        option(conn_option)
    {}

    SQLUnsupportedOptionException(const std::string& reason, const std::string& conn_option) :
        SQLException(reason, "", 0),
        option(conn_option)
    {}

    const char* getConnectionOption() const {
        return option.c_str();
    }

    ~SQLUnsupportedOptionException() noexcept {};

protected:
    const std::string option;
};


#endif
