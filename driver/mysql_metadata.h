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

public:
    MySQL_MetaData(Statement* const stmt,
                   ACE_Refcounted_Auto_Ptr<ConnectionWrapper, ACE_Lock> capi,
                   ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);
    
    virtual ~MySQL_MetaData();

    Connection* getConnection();

    SQLString getURL();

    SQLString getUserName();

    ResultSet* getSchemas();

    unsigned int getDatabaseVersion();

    unsigned int getDriverVersion();

    SQLString& getDriverName();

    unsigned getMaxConnections();

    ResultSet* getTables(const SQLString& catalog,
                                 const SQLString& schema,
                                 const SQLString& tableName,
                                 std::list<SQLString>& types);

    ResultSet* getPrimaryKeys(const SQLString& catalog,
                                      const SQLString& schema,
                                      const SQLString& table);

    ResultSet* getProcedures(const SQLString& catalog,
                                     const SQLString& schema,
                                     const SQLString& procedureName);

    bool isReadOnly();

    bool allProceduresAreCallable();

    bool allTablesAreSelectable();

};

#endif  // _MYSQL_METADATA_H_