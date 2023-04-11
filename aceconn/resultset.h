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
    enum class CursorMode {
        CLOSE_CURSORS_AT_COMMIT,
        HOLD_CURSORS_OVER_COMMIT
    };

    enum class FetchDirection {
        FETCH_FORWARD,
        FETCH_REVERSE,
        FETCH_UNKNOWN
    };

    virtual ~ResultSet() {}

    virtual void close() = 0;

    virtual void cancelRowUpdates() = 0;

    virtual void clearWarnings() = 0;

    virtual ResultSetMetaData* getMetadata() const = 0;

    virtual void getWarnings() = 0;

    virtual size_t getRow() const = 0;

    virtual SQLString getCursorName() = 0;

    virtual void setFetchSize(size_t rows) = 0;

    virtual uint32_t findColumn(const SQLString& columnLabel) const = 0;

    virtual int32_t getInt(uint32_t columnIndex) const = 0;
    virtual int32_t getInt(const SQLString& columnLabel) const = 0;

    virtual long double getDouble(uint32_t columnIndex) const = 0;
    virtual long double getDouble(const SQLString &columnLabel) const = 0;

    virtual bool getBoolen(uint32_t columnIndex) const = 0;
    virtual bool getBoolen(const SQLString &columnLabel) const = 0;

    virtual SQLString getString(uint32_t columnIndex) const = 0;
    virtual SQLString getString(const SQLString &columnLabel) const = 0;

    virtual RowID* getRowId(uint32_t columnIndex) const = 0;
    virtual RowID* getRowId(const SQLString &columnLabel) const = 0;

    virtual bool isNull(uint32_t columnIndex) const = 0;
    virtual bool isNull(const SQLString &columnLabel) const = 0;

    virtual bool isClosed() const = 0;

    virtual bool isFirst() const = 0;

    virtual bool isLast() const = 0;

    virtual bool rowDeleted() = 0;

    virtual bool rowInserted() = 0;

    virtual bool rowUpdated() = 0;

    virtual size_t rowsCount() const = 0;
};

#endif
