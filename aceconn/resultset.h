#ifndef _SQL_RESULTSET_H_
#define _SQL_RESULTSET_H_

#include <map>
#include <list>
#include <iostream>
#include "sqlstring.h"
#include "resultset_metadata.h"

class RowID {

public:
    virtual ~RowID() {}
};

class ResultSet {

public:
    enum {
        FETCH_FORWARD,
        FETCH_REVERSE,
        FETCH_UNKNOWN
    };

    virtual ~ResultSet() {}

    virtual bool absolute(int row) = 0;

    virtual void close() = 0;

    virtual ResultSetMetaData *getMetadata() const = 0;

    virtual uint32_t findColumn(const SQLString& columnLabel) const = 0;

    virtual int32_t getInt(uint32_t columnIndex) const = 0;
    virtual int32_t getInt(const SQLString& columnLabel) const = 0;

    virtual SQLString getString(uint32_t columnIndex) const = 0;
    virtual SQLString getString(const SQLString &columnLabel) const = 0;

    virtual bool isClosed() const = 0;

    virtual bool isNull(uint32_t columnIndex) const = 0;
    virtual bool isNull(const SQLString& columnLabel) const = 0;

    virtual size_t rowsCount() const = 0;
};

#endif
