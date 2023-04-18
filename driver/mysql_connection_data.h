#ifndef _MYSQL_CONNECTION_DATA_H_
#define _MYSQL_CONNECTION_DATA_H_

#include <ace/Auto_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/resultset.h>
#include <aceconn/connection.h>
#include <list>
#include "mysql_util.h"
#include "mysql_metadata.h"
#include "mysql_warning.h"
#include "driver/common.h"

class MySQL_DebugLogger;
class MySQL_MetaData;

class MySQL_ConnectionData {

public:
    MySQL_ConnectionData(ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger) :
        closed(false),
        autocommit(false),
        tx_isolation(TRANSACTION_ISOLATION::TRANSACTION_READ_COMMITTED),
        is_valid(false),
        sql_mode_set(false),
        cache_sql_mode(false),
        reconnect(false),
        stmt_rs_type(ResultSet::ResultSetType::SCROLL_INSENSITIVE),
        pstmt_rs_type(ResultSet::ResultSetType::SCROLL_INSENSITIVE),
        logger(logger),
        meta(nullptr)
    {}

    ~MySQL_ConnectionData() {}

    bool closed;
    bool autocommit;
    TRANSACTION_ISOLATION tx_isolation;
    bool is_valid;
    bool sql_mode_set;
    bool cache_sql_mode;
    bool reconnect;
    ResultSet::ResultSetType stmt_rs_type;
    ResultSet::ResultSetType pstmt_rs_type;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;
    ACE_Auto_Ptr<MySQL_ConnectionData> meta;
    SQLString sql_mode;
};

#endif  // _MYSQL_CONNECTION_DATA_H_