#ifndef _SQL_PREPARED_STATEMENT_H_
#define _SQL_PREPARED_STATEMENT_H_

#include <iostream>
#include "statement.h"

class Connection;
class ResultSet;
class ResultSetMetaData;
class ParameterMetaData;

class PreparedStatement : public Statement {
public:
    virtual ~PreparedStatement() {}

    virtual ParameterMetaData *getParameterMetaData() = 0;

    virtual void clearParameters() = 0;

    virtual bool execute(const SQLString& sql) = 0;
    virtual bool execute() = 0;

    virtual ResultSet *executeQuery(const SQLString& sql) = 0;
    virtual ResultSet *executeQuery() = 0;

    virtual int executeUpdate(const SQLString& sql) = 0;
    virtual int executeUpdate() = 0;

    virtual void setInt(unsigned int parameterIndex, int32_t value) = 0;
    virtual void setDouble(unsigned int parameterIndex, double value) = 0;
    virtual void setBoolean(unsigned int parameterIndex, bool value) = 0;
    virtual void setString(unsigned int parameterIndex, SQLString& value) = 0;

    virtual PreparedStatement *setResultSetType(ResultSet::ResultSetType type) = 0;
};

#endif
