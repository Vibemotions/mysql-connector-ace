#ifndef _SQL_METADATA_H_
#define _SQL_METADATA_H_

#include <string>
#include <list>
#include "datatype.h"
#include "sqlstring.h"

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
        typeNoNulls = 0,
        typeNullable = 1,
        typeNullableUnknown = 2
    };

    enum {
        tableIndexClustered = 0,
        tableIndexHashed,
        tableIndexOther,
        tableIndexStatistic
    };

    virtual bool allProceduresAreCallable() = 0;

    virtual bool allTablesAreSelectable() = 0;
};

#endif
