#ifndef _MYSQL_WARNING_H_
#define _MYSQL_WARNING_H_

#include <aceconn/warning.h>
#include <aceconn/connection.h>
#include <ace/Auto_Ptr.h>

class MySQL_Warning : public SQLWarning {

private:
    const SQLString sql_state;
    const int errNo;
    const SQLString description;
    ACE_Auto_Ptr<MySQL_Warning> next;

public:
    MySQL_Warning(const SQLString& reason, const SQLString& SQLState, int vendorCode);

    MySQL_Warning(const SQLString& reason, const SQLString& SQLState);

    MySQL_Warning(const SQLString& reason);

    MySQL_Warning();

    const SQLString& getMessage() const;

    const SQLString& getSQLState() const;

    int getErrorCode() const;

    const SQLWarning* getNextWarning() const;

    void setNextWarning(const SQLWarning* next);

    ~MySQL_Warning();

private:
    void setNextWarning(const SQLWarning* next);

    MySQL_Warning(const MySQL_Warning&);

    MySQL_Warning(const SQLWarning&);

    const MySQL_Warning& operator=(const MySQL_Warning&);

};

const SQLString& errToSqlState(int32_t errCode, SQLString& state);

MySQL_Warning* loadMysqlWarnings(Connection* connection,
                                 unsigned int warningsCount = 0);

#endif  // _MYSQL_WARNING_H_