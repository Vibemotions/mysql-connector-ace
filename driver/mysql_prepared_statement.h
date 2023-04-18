#ifndef _MYSQL_PREPARED_STATEMENT_H_
#define _MYSQL_PREPARED_STATEMENT_H_

#include <ace/Auto_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/prepared_statement.h>
#include <aceconn/parameter_metadata.h>

class MySQL_DebugLogger;
class MySQL_ParamBind;
class MySQL_ParameterMetaData;
class MySQL_PreparedResultSetMetaData;
class MySQL_ResultBind;
class MySQL_Warning;
class MySQL_Connection;

class StatementWrapper;

class MySQL_Prepared_Statement : public PreparedStatement {

protected:
    ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock> proxy;
    MySQL_Connection* connection;
    ResultSet::ResultSetType resultset_type;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

    ACE_Refcounted_Auto_Ptr<MySQL_ResultBind, ACE_Lock> result_bind;
    ACE_Auto_Ptr<MySQL_ParamBind> param_bind;
    ACE_Auto_Ptr<MySQL_Warning> warnings;
    unsigned int warning_count;
    unsigned int param_count;
    bool isClosed;

public:
    MySQL_Prepared_Statement(ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock>& stmt,
                             MySQL_Connection* conn,
                             ResultSet::ResultSetType rs_type,
                             ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    ~MySQL_Prepared_Statement();

    ParameterMetaData *getParameterMetaData();

    void clearParameters();

    bool execute(const SQLString& sql);
    bool execute();

    ResultSet *executeQuery(const SQLString& sql);
    ResultSet *executeQuery();

    int executeUpdate(const SQLString& sql);
    int executeUpdate();

    void setInt(unsigned int parameterIndex, int32_t value);
    void setDouble(unsigned int parameterIndex, double value);
    void setBoolean(unsigned int parameterIndex, bool value);
    void setString(unsigned int parameterIndex, SQLString& value);

    PreparedStatement *setResultSetType(ResultSet::ResultSetType type);

private:
    MySQL_Prepared_Statement(const MySQL_Prepared_Statement&);
    void operator=(MySQL_Prepared_Statement&);
};


#endif  // _MYSQL_PREPARED_STATEMENT_H_