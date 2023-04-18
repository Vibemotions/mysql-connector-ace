#ifndef _MYSQL_STATEMENT_H_
#define _MYSQL_STATEMENT_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <ace/Bound_Ptr.h>
#include <aceconn/statement.h>
#include <aceconn/resultset.h>
#include <mysql_resultbind.h>
#include <mysql_warning.h>
#include <mysql_util.h>

class MySQL_Connection;
class MySQL_DebugLogger;

class ResultSetWrapper;
class ConnectionWrapper;

class MySQL_Statement : public Statement {

protected:
    MySQL_Connection* connection;
    ACE_Weak_Bound_Ptr<ConnectionWrapper, ACE_Lock> proxy;
    ResultSet::ResultSetType rs_type;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

    ACE_Auto_Ptr<MySQL_Warning> warnings;
    MySQL_AttrBind attrbind;
    bool isClosed;
    unsigned int warningsCount;

public:
    MySQL_Statement(MySQL_Connection* conn,
                    ACE_Refcounted_Auto_Ptr<ConnectionWrapper, ACE_Lock>& proxy,
                    ResultSet::ResultSetType rs_type,
                    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    ~MySQL_Statement();

    void close();

    void clearWarnings();

    bool execute(const SQLString& sql);

    ResultSet* executeQuery(const SQLString& sql);

    int executeUpdate(const SQLString& sql);

    SQLWarning *getWarnings();

    ResultSet *getResultSet();

    ResultSet::ResultSetType getResultSetType();

    size_t getFetchSize();

    unsigned int getQueryTimeout();

    void setCursorName(const SQLString& name);

    void setFetchSize(size_t rows);

    void setMaxRows(unsigned int max);

    void setQueryTimeout(unsigned int seconds);

    int setQueryAttrInt(const SQLString& name, int32_t value);
    int setQueryAttrDouble(const SQLString &name, double value);
    int setQueryAttrBoolen(const SQLString &name, bool value);
    int setQueryAttrString(const SQLString &name, const SQLString& value);
    int setQueryAttrNull(const SQLString &name);

    void clearAttributes();
    
private:
    MySQL_Statement(const MySQL_Statement&);
    void operator=(MySQL_Statement&);
};

#endif  // _MYSQL_STATEMENT_H_