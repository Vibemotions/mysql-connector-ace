#ifndef _SQL_CONNECTION_H_
#define _SQL_CONNECTION_H_

#include <map>

#include "warning.h"
#include "sqlstring.h"
#include "variant.h"

/*
    Options used on ConnectOptionsMap
*/

/*
    Connect related
*/
#define OPT_HOSTNAME    "hostName"
#define OPT_USERNAME    "userName"
#define OPT_PASSWORD    "password"
#define OPT_PORT        "port"
#define OPT_SOCKET      "socket"
#define OPT_SCHEMA      "schema"

/*
    SSL related
*/
#define OPT_SSL_MODE                "ssl-mode"
#define OPT_SSL_KEY                 "ssl-key"
#define OPT_SSL_CERT                "ssl-cert"
#define OPT_SSL_CA                  "ssl-ca"
#define OPT_SSL_CAPATH              "ssl-capath"
#define OPT_SSL_CIPHER              "ssl-cipher"
#define OPT_SSL_CRL                 "ssl-crl"
#define OPT_SSL_CRLPATH             "ssl-crlpath"
#define OPT_SSL_SERVER_PUBLIC_KEY   "rsaKey"
#define OPT_TLS_VERSION             "tls-version"

/*
    Connection related
*/
#define OPT_RECONNECT           "OPT_RECONNECT"
#define OPT_RETRY_COUNT         "OPT_RETRY_COUNT"
#define OPT_CONNECT_TIMEOUT     "OPT_CONNECT_TIMEOUT"
#define OPT_READ_TIMEOUT        "OPT_READ_TIMEOUT"
#define OPT_WRITE_TIMEOUT       "OPT_WRITE_TIMEOUT"
#define OPT_MAX_ALLOWED_PACKET  "OPT_MAX_ALLOWED_PACKET"
#define OPT_NET_BUFFER_LENGTH   "OPT_NET_BUFFER_LENGTH"

/*
    Connection Attributes
*/
#define OPT_CONNECT_ATTR_ADD    "OPT_CONNECT_ATTR_ADD"
#define OPT_CONNECT_ATTR_DELETE "OPT_CONNECT_ATTR_DELETE"
#define OPT_CONNECT_ATTR_RESET  "OPT_CONNECT_ATTR_RESET"

/*
    Authentication
*/
#define OPT_
#define OPT_
#define OPT_
#define OPT_
#define OPT_

/*
    Character set results and Metadata
*/

/*
    Client side options
*/

/*
    Auth plugin options
*/

typedef Variant ConnectPropertyVal;

typedef std::map<SQLString, ConnectPropertyVal> ConnectOptionsMap;

class DatabaseMetaData;
class PreparedStatement;
class Statement;
class Driver;

typedef enum transaction_isolation {

} enum_transaction_isolation;

enum ssl_mode {

};

class Savepoint {

};

class Connection {

};

#endif
