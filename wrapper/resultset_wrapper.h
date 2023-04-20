#ifndef _RESULTSET_WRAPPER_H_
#define _RESULTSET_WRAPPER_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <driver/mysql_debug.h>
#include <driver/common.h>

class MySQLCAPI;
struct MYSQL;
struct MYSQL_FIELD;
struct MYSQL_RES;

class ResultSetWrapper {

    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;
    ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock> capi;
    MYSQL* mysql;
    MYSQL_RES* res;

public:
    ResultSetWrapper() = default;
    ResultSetWrapper(const ResultSetWrapper&) = delete;
    ResultSetWrapper& operator=(const ResultSetWrapper&) = delete;

    ResultSetWrapper(MYSQL&, MYSQL_RES&, ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock>&);
    ~ResultSetWrapper();

    unsigned long server_version();

    void data_seek(uint64_t);

    MYSQL_FIELD& fetch_field();

    unsigned long fetch_length();

    MYSQL_ROW fetch_row();

    unsigned int num_fields();

    uint64_t num_rows();
};

#endif