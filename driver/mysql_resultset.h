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
};

#endif  // _MYSQL_RESULTSET_H_