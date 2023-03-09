#ifndef _SQL_RESULTSET_METADATA_H_
#define _SQL_RESULTSET_METADATA_H_

#include "sqlstring.h"
#include "datatype.h"

class ResultSetMetaData {

public:
    enum {
        columnNoNulls,
        columnNullable,
        columnNullableUnknown
    };

    virtual unsigned int getColumnCount() = 0;

    virtual SQLString getCatalogName(unsigned int column) = 0;

    virtual SQLString getColumnName(unsigned int column) = 0;

    virtual int getColumnType(unsigned int column) = 0;

    virtual SQLString getColumnTypeName(unsigned int column) = 0;

    virtual SQLString getSchemaName(unsigned int column) = 0;

    virtual SQLString getTableName(unsigned int column) = 0;

    virtual bool isAutoIncrement(unsigned int column) = 0;

    virtual bool isNullable(unsigned int column) = 0;

    virtual bool isNumeric(unsigned int column) = 0;

    virtual bool isReadOnly(unsigned int column) = 0;

    virtual bool isWritable(unsigned int column) = 0;

protected:
    virtual ~ResultSetMetaData() {}
};

#endif
