#ifndef _SQL_METADATA_H_
#define _SQL_METADATA_H_

#include <string>
#include <list>
#include "datatype.h"
#include "sqlstring.h"

class ResultSet;
class Connection;

class DatabaseMetaData {

protected:
    ~DatabaseMetaData() {}

public:
    enum {
        attributeNoNulls = 0,
        attributeNullable,
        attributeNullableUnknown
    };

    enum {
        columnNoNulls = 0,
        columnNullable,
        columnNullableUnknown
    };

    enum {
        procedureColumnIn = 0,
        procedureColumnInOut,
        procedureColumnOut,
        procedureColumnResult,
        procedureColumnReturn,
        procedureColumnUnknown,
        procedureNoNulls,
        procedureNoResult,
        procedureNullable,
        procedureNullableUnknown,
        procedureResultUnknown,
        procedureReturnsResult,
    };

    enum {
        tableIndexClustered = 0,
        tableIndexHashed,
        tableIndexOther,
        tableIndexStatistic
    };

    enum {
        typeNoNulls = 0,
        typeNullable = 1,
        typeNullableUnknown = 2
    };

    virtual Connection *getConnection() = 0;

    virtual SQLString getURL() = 0;

    virtual SQLString getUserName() = 0;

    virtual ResultSet* getSchemas() = 0;

    virtual unsigned int getDatabaseVersion() = 0;

    virtual unsigned int getDriverVersion() = 0;

    virtual SQLString &getDriverName() = 0;

    virtual unsigned getMaxConnections() = 0;

    virtual ResultSet* getTables(const SQLString& catalog, const SQLString& schema, const SQLString& tableName, std::list<SQLString>& types) = 0;

    virtual ResultSet* getPrimaryKeys(const SQLString& catalog, const SQLString& schema, const SQLString& table) = 0;

    virtual ResultSet* getProcedures(const SQLString& catalog, const SQLString& schema, const SQLString& procedureName) = 0;

    virtual bool isReadOnly() = 0;

    virtual bool allProceduresAreCallable() = 0;

    virtual bool allTablesAreSelectable() = 0;
};

#endif
