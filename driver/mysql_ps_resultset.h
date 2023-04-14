#ifndef _MYSQL_PS_RESULTSET_H_
#define _MYSQL_PS_RESULTSET_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <ace/Auto_Ptr.h>
#include <aceconn/resultset.h>
#include <map>

class MySQL_DebugLogger;
class MySQL_Prepared_Statement;
class MySQL_PreparedResultSetMetaData;
class MySQL_ResultBind;

class StatementWrapper;

typedef std::map<SQLString, unsigned int> FieldNameIndexMap;
class MySQL_Prepared_ResultSet : public ResultSet {

    ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock> proxy;
    
    mutable uint32_t last_queried_column;
    
    unsigned int num_fields;
    uint64_t num_rows;
    uint64_t row_pos;
    
    FieldNameIndexMap field_name_to_index_map;
    
    const MySQL_Prepared_Statement* stmt;
    
    bool isValid;

    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

    ACE_Auto_Ptr<MySQL_PreparedResultSetMetaData> rs_meta;

    ACE_Refcounted_Auto_Ptr<MySQL_ResultBind, ACE_Lock> result_bind;

    ResultSet::ResultSetType rs_type;

protected:
    void checkValid() const;
    void checkScrollable() const;
    bool isScrollable() const;
    bool isOutofRange() const;
    void seek();

public:
    MySQL_Prepared_ResultSet(ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock>& stmt,
                             ACE_Refcounted_Auto_Ptr<MySQL_ResultBind, ACE_Lock>& result_bind,
                             ResultSet::ResultSetType rs_type,
                             MySQL_Prepared_Statement* pre_stmt,
                             ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    virtual ~MySQL_Prepared_ResultSet();

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
};

#endif  // _MYSQL_PS_RESULTSET_H_