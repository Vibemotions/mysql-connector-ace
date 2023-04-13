#ifndef _MYSQL_RESULTSET_H_
#define _MYSQL_RESULTSET_H_

#include <ace/Auto_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <ace/Bound_Ptr.h>
#include <aceconn/resultset.h>
#include <driver/common.h>

class MySQL_Statement;
class MySQL_DebugLogger;
class MySQL_ResultSetMetaData;

class ConnectionWrapper;
class ResultSetWrapper;

class MySQL_ResultSet : public ResultSet {
    MYSQL_ROW row;
    ACE_Refcounted_Auto_Ptr<ResultSetWrapper, ACE_Lock> result;
    ACE_Weak_Bound_Ptr<ConnectionWrapper, ACE_Lock> proxy;
    unsigned int num_fields;
    uint64_t num_rows;
    uint64_t row_pos;
    /*
        0 : before the first row
        1 : the first row
        num_rows + 1 : after the last row
    */

   typedef std::map<SQLString, unsigned int> FieldNameIndexMap;
   FieldNameIndexMap field_name_to_index_map;

   mutable bool was_null;

    // updated by calling ResultSet::getInt() or getDouble() ...
   mutable uint32_t last_quired_column;

   const MySQL_Statement* stmt;

   ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

   ACE_Auto_Ptr<MySQL_ResultSetMetaData> rs_meta;

   ResultSet::ResultSetType rs_type;

   unsigned long server_version;

protected:
    void checkValid() const;
    void checkSrollable() const;
    bool isScrollable() const;
    bool isOutofRange() const;
    void seek();

    MYSQL_FIELD* getFieldMeta(unsigned int columnIndex) const;

public:
    MySQL_ResultSet(ACE_Refcounted_Auto_Ptr<ResultSetWrapper, ACE_Lock> res,
                    ACE_Weak_Bound_Ptr<ConnectionWrapper, ACE_Lock> proxy,
                    ResultSet::ResultSetType rs_type,
                    MySQL_Statement* stmt,
                    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    virtual ~MySQL_ResultSet();

    void close();

    void cancelRowUpdates();

    void clearWarnings();

    ResultSetMetaData* getMetadata() const;

    void getWarnings();

    size_t getRow() const;

    SQLString getCursorName();

    void setFetchSize(size_t rows);

    uint32_t findColumn(const SQLString& columnLabel) const;

    int32_t getInt(uint32_t columnIndex) const;
    int32_t getInt(const SQLString& columnLabel) const;

    long double getDouble(uint32_t columnIndex) const;
    long double getDouble(const SQLString &columnLabel) const;

    bool getBoolen(uint32_t columnIndex) const;
    bool getBoolen(const SQLString &columnLabel) const;

    SQLString getString(uint32_t columnIndex) const;
    SQLString getString(const SQLString &columnLabel) const;

    RowID* getRowId(uint32_t columnIndex) const;
    RowID* getRowId(const SQLString &columnLabel) const;

    bool isNull(uint32_t columnIndex) const;
    bool isNull(const SQLString &columnLabel) const;

    bool isClosed() const;

    bool isFirst() const;

    bool isLast() const;

    bool rowDeleted();

    bool rowInserted();

    bool rowUpdated();

    size_t rowsCount() const;

private:
    MySQL_ResultSet(const MySQL_ResultSet&);
    void operator=(MySQL_ResultSet&);
};

#endif  // _MYSQL_RESULTSET_H_