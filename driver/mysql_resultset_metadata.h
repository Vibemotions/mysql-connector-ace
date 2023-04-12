#ifndef _MYSQL_RESULTSET_METADATA_H_
#define _MYSQL_RESULTSET_METADATA_H_

#include <ace/Bound_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/resultset_metadata.h>
#include <driver/common.h>

struct MYSQL_FIELD;

class ResultSetWrapper;

class MySQL_DebugLogger;

class MySQL_ResultSetMetaData : public ResultSetMetaData {

public:
    MySQL_ResultSetMetaData(ACE_Refcounted_Auto_Ptr<ResultSetWrapper, ACE_Lock> result,
                            ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger);
    
    virtual ~MySQL_ResultSetMetaData();

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
    void checkValid() const;

    void checkColumnIndex(unsigned int columnIndex) const;

    MYSQL_FIELD* getFieldMeta(unsigned int columnIndex) const;

private:
    MySQL_ResultSetMetaData(const MySQL_ResultSetMetaData&);
    void operator=(MySQL_ResultSetMetaData&);

    ACE_Weak_Bound_Ptr<ResultSetWrapper, ACE_Lock> result;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;
    unsigned long server_version;
    unsigned int num_fields;
};

#endif  // _MYSQL_RESULTSET_METADATA_H_