#ifndef _CONNECTION_WRAPPER_H_
#define _CONNECTION_WRAPPER_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/sqlstring.h>
#include <driver/common.h>
#include <resultset_wrapper.h>
#include <statement_wrapper.h>

class MySQLCAPI;
struct MYSQL_BIND;

class ConnectionWrapper {

    ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock> capi;
    MYSQL* mysql;
    SQLString server_info;

public:
    ConnectionWrapper() = delete;
    ConnectionWrapper(const ConnectionWrapper&) = delete;
    ConnectionWrapper& operator=(const ConnectionWrapper&) = delete;

    ConnectionWrapper(ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock>);

    virtual ~ConnectionWrapper();

    uint64_t affected_rows();

    bool autocommit(bool);

    bool connect(const SQLString& host,
                 const SQLString& user,
                 const SQLString& password,
                 const SQLString& database,
                 unsigned int port,
                 unsigned long client_flag);

    bool commit();

    void debug(const SQLString&);

    unsigned int errNo();

    SQLString error();

    SQLString escape_string(const SQLString&);

    unsigned int field_count();

    unsigned long get_client_version();

    unsigned long get_server_version();

    const SQLString& get_server_info();

    bool more_results();

    int next_result();

    int options(CONNECTION_OPTION, const void*);
    int options(CONNECTION_OPTION, const int&);
    int options(CONNECTION_OPTION, const bool&);
    int options(CONNECTION_OPTION, const SQLString&);
    int options(CONNECTION_OPTION, const SQLString&, const SQLString&);
    int options(CONNECTION_OPTION, const int&, const SQLString&);
    
    int get_option(CONNECTION_OPTION, const void*);
    int get_option(CONNECTION_OPTION, const int&);
    int get_option(CONNECTION_OPTION, const bool&);
    int get_option(CONNECTION_OPTION, const SQLString&);

    int plugin_option(int plugin_type,
                      const SQLString& plugin_name,
                      const SQLString& option,
                      const void*);

    int plugin_option(int plugin_type,
                      const SQLString& plugin_name,
                      const SQLString& option,
                      const SQLString& value);

    int get_plugin_option(int plugin_type,
                          const SQLString& plugin_name,
                          const SQLString& option,
                          const SQLString& value);

    bool query_attr(unsigned number, const char** names, MYSQL_BIND*);
    
    int query(const SQLString&);

    int ping();

    bool rollback();

    SQLString sqlstate();

    bool ssl_set(const SQLString& key,
                 const SQLString& cert,
                 const SQLString& ca,
                 const SQLString& capath,
                 const SQLString& cipher);

    SQLString info();

    int use_protocol(PROTOCOL_TYPE protocol);

    ResultSetWrapper* store_result();

    ResultSetWrapper* use_result();

    StatementWrapper& stmt_init();

    unsigned int warning_count();
};

#endif