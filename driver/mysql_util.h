#ifndef _MYSQL_UTIL_H_
#define _MYSQL_UTIL_H_

#include <aceconn/sqlstring.h>
#include <aceconn/exception.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <driver/common.h>

class MySQL_DebugLogger;

class ConnectionWrapper;
class StatementWrapper;

void throwSQLException(ConnectionWrapper& proxy);
void throwSQLException(StatementWrapper& proxy);

int mysql_string_to_datatype(const SQLString& name);
int mysql_type_to_datatype(const MYSQL_FIELD* const field, unsigned long server_version);
const char* mysql_type_to_string(const MYSQL_FIELD* const field,
                                 ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);


#endif  // _MYSQL_UTIL_H_