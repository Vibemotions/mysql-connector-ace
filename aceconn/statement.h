#ifndef _SQL_STATEMENT_H_
#define _SQL_STATEMENT_H_

#include <string>

#include "resultset.h"

class ResultSet;
class Connection;
class SQLWarning;

class Statement {

public:
    virtual ~Statement() {};

    virtual Connection *getConnection() = 0;

    virtual void close() = 0;

    virtual bool execute(const SQLString& sql) = 0;

    virtual ResultSet *executeQuery(const SQLString& sql) = 0;

    virtual int executeUpdate(const SQLString& sql) = 0;

    virtual ResultSet *getResultSet() = 0;

    virtual SQLWarning *getWarnings() = 0;

    virtual void setCursorName(const SQLString& name) = 0;

    virtual void setMaxRows(unsigned int max) = 0;

    virtual void setQueryTimeout(unsigned int seconds) = 0;

    virtual int setQueryAttrInt(const SQLString& name, int32_t value) = 0;
    virtual int setQueryAttrDouble(const SQLString &name, double value) = 0;
    virtual int setQueryAttrNull(const SQLString &name) = 0;

    virtual void clearAttributes() = 0;
};
#endif
