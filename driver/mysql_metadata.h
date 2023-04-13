#ifndef _MYSQL_METADATA_H_
#define _MYSQL_METADATA_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/metadata.h>
#include <aceconn/statement.h>
#include <map>

class ResultSet;
class Statement;

class MySQL_Connection;
class MySQL_DebugLogger;

class ConnectionWrapper;

class MySQL_CAPI;

class MySQL_MetaData : public DatabaseMetaData {

    Statement* stmt;
    MySQL_Connection* connection;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;
    ACE_Refcounted_Auto_Ptr<ConnectionWrapper, ACE_Lock> proxy;
    unsigned long server_version;
};

#endif  // _MYSQL_METADATA_H_