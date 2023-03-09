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

    virtual void clearParameters() = 0;

    virtual bool execute(const SQLString& sql) = 0;
    virtual bool execute() = 0;
};

#endif
