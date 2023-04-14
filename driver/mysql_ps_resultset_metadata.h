#ifndef _MYSQL_PS_RESULTSET_METADATA_H_
#define _MYSQL_PS_RESULTSET_METADATA_H_

#include <aceconn/resultset.h>
#include <aceconn/resultset_metadata.h>
#include <driver/common.h>
#include <ace/Auto_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>

class ResultSetWrapper;
class StatementWrapper;

class MySQL_DebugLogger;

class MySQL_PreparedResultSetMetaData : ResultSetMetaData {

    ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock> proxy;
    
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;
    
    ACE_Auto_Ptr<ResultSetWrapper> res_meta;

    unsigned int num_fields;

    unsigned long server_version;

public:
    MySQL_PreparedResultSetMetaData(ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock>& proxy,
                                    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    virtual ~MySQL_PreparedResultSetMetaData();

    SQLString getSchemaName(unsigned int column);

    SQLString getTableName(unsigned int column);

    SQLString getColumnName(unsigned int column);
    
    SQLString getColumnLabel(unsigned int column);

    SQLString getColumnTypeName(unsigned int column);

    SQLString getColumnCharset(unsigned int column);

    int getColumnType(unsigned int column);

    unsigned int getColumnCount();

    unsigned int getPrecision(unsigned int column);

    unsigned int getScale(unsigned int column);

    bool isAutoIncrement(unsigned int column);

    bool isCaseSensitive(unsigned int column);

    bool isNullable(unsigned int column);

    bool isNumeric(unsigned int column);

    bool isReadOnly(unsigned int column);

    bool isWritable(unsigned int column);

protected:
    void checkColumnIndex(unsigned int columnIndex) const;

    MYSQL_FIELD* getFieldMeta(unsigned int columnIndex) const;

private:
    MySQL_PreparedResultSetMetaData(const MySQL_PreparedResultSetMetaData&);

    void operator=(MySQL_PreparedResultSetMetaData&);
};


#endif