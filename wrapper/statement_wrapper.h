#ifndef _STATEMENT_WRAPPER_H_
#define _STATEMENT_WRAPPER_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/sqlstring.h>
#include <driver/common.h>

class MySQLCAPI;
class ResultSetWrapper;
class ConnectionWrapper;
struct MYSQL_RES;
struct MYSQL_BIND;
struct MYSQL_STMT;

class StatementWrapper {

    ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock> capi;
    MYSQL_STMT* stmt;
    ConnectionWrapper* conn;

public:
    StatementWrapper() = delete;
    StatementWrapper(const StatementWrapper&) = delete;
    StatementWrapper& operator=(const StatementWrapper&) = delete;

    StatementWrapper(MYSQL_STMT&, ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock>&);
    ~StatementWrapper();

    unsigned long server_version();

    uint64_t affected_rows();

    bool attr_set(STATEMENT_OPTION option, const void* arg);

    bool bind_param(MYSQL_BIND&);

    bool bind_result(MYSQL_BIND&);

    void data_seek(uint64_t);

    unsigned int errNo();

    SQLString error();

    int execute();

    int fetch();

    unsigned int field_count();

    bool more_results();

    int next_result();

    uint64_t num_rows();

    unsigned int param_count();

    int prepare(const SQLString&);

    ResultSetWrapper& result_metadata();

    SQLString sql_state();

    int store_result();

    int stmt_next_result();

    bool stmt_free_result();

    unsigned int warning_count();
};

#endif