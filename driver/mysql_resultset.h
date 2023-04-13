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


private:
    MySQL_ResultSet(const MySQL_ResultSet&);
    void operator=(MySQL_ResultSet&);
};

#endif  // _MYSQL_RESULTSET_H_