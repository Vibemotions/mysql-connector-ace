#ifndef _MYSQL_CAPI_H_
#define _MYSQL_CAPI_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/sqlstring.h>
#include <driver/common.h>

class MySQLCAPI {

public:
    virtual my_ulonglong affected_rows(MYSQL *) = 0;

    virtual my_bool autocommit(MYSQL *, my_bool) = 0;

    virtual void close(MYSQL *mysql) = 0;

    virtual my_bool commit(MYSQL *mysql) = 0;

    virtual void data_seek(MYSQL_RES *, my_ulonglong) = 0;

    virtual void debug(const char *) = 0;

    virtual unsigned int mysql_errno(MYSQL *mysql) = 0;

    virtual const char * error(MYSQL *mysql) = 0;

    virtual MYSQL_FIELD * fetch_field(MYSQL_RES *) = 0;

    virtual MYSQL_FIELD * fetch_field_direct (MYSQL_RES *, unsigned int) = 0;

    virtual unsigned long * fetch_lengths(MYSQL_RES * ) = 0;

    virtual MYSQL_ROW fetch_row(MYSQL_RES * ) = 0;

    virtual unsigned int field_count(MYSQL *) = 0;

    virtual void free_result(MYSQL_RES * ) = 0;

    virtual unsigned long get_client_version() = 0;

    virtual const char * get_server_info(MYSQL *) = 0;

    virtual unsigned long get_server_version(MYSQL *) = 0;

    virtual void get_character_set_info(MYSQL *, void *) = 0;

    virtual const char * info(MYSQL *mysql) = 0;

    virtual MYSQL * init(MYSQL *mysql) = 0;

    virtual int library_init(int argc, char **argv, char **groups) = 0;

    virtual void library_end() = 0;

    virtual my_bool more_results(MYSQL *) = 0;

    virtual int next_result(MYSQL *) = 0;

    virtual unsigned int num_fields(MYSQL_RES * ) = 0;

    virtual my_ulonglong num_rows(MYSQL_RES * ) = 0;

    virtual int options(MYSQL *, enum mysql_option option , const void *arg) = 0;

    virtual int options(MYSQL *, enum mysql_option option , const void *arg1, const void *arg2) = 0;

    virtual int get_option(MYSQL *, enum mysql_option option , const void *arg) = 0;

    virtual st_mysql_client_plugin* client_find_plugin(MYSQL *, const char *plugin_name, int plugin_type) = 0;

    virtual int plugin_options(st_mysql_client_plugin*, const char *option, const void *value) = 0;

    virtual int plugin_get_option(st_mysql_client_plugin*, const char *option, void *value) =0;

    virtual int ping(MYSQL *) = 0;

    virtual int query(MYSQL *, const char *) = 0;

    virtual MYSQL * real_connect(MYSQL * mysql,
                const char *  host,
                const char *  user,
                const char *  passwd,
                const char *  db,
                unsigned int  port,
                const char *  unix_socket,
                unsigned long client_flag) = 0;

    virtual MYSQL * real_connect_dns_srv(MYSQL * mysql,
                                         const char *  host,
                                         const char *  user,
                                         const char *  passwd,
                                         const char *  db,
                                         unsigned long client_flag) = 0;

    virtual bool bind_param(MYSQL *mysql, unsigned n_params,
                            MYSQL_BIND *binds, const char **names) = 0;

    virtual unsigned long real_escape_string(MYSQL * mysql, char * to, const char * from, unsigned long length) = 0;

    virtual int real_query(MYSQL *, const char *, unsigned long) = 0;

    virtual my_bool rollback(MYSQL *) = 0;

    virtual const char * sqlstate(MYSQL *) = 0;

    virtual my_bool ssl_set(MYSQL * mysql,
                            const char * key,
                            const char * cert,
                            const char * ca,
                            const char * capath,
                            const char * cipher) = 0;

    virtual MYSQL_RES * store_result(MYSQL *) = 0;

    virtual MYSQL_RES * use_result(MYSQL *) = 0;

    virtual unsigned int warning_count(MYSQL *) = 0;

    /* Methods - wrappers of prepared statement stmt_* functions */
    virtual my_ulonglong  stmt_affected_rows (MYSQL_STMT *) = 0;

    virtual my_bool stmt_attr_set(MYSQL_STMT *stmt, enum enum_stmt_attr_type option , const void *arg) = 0;

    virtual my_bool stmt_bind_param(MYSQL_STMT *, MYSQL_BIND *) = 0;

    virtual my_bool stmt_bind_result(MYSQL_STMT *, MYSQL_BIND *) = 0;

    virtual my_bool stmt_close(MYSQL_STMT *) = 0;

    virtual void stmt_data_seek(MYSQL_STMT *, my_ulonglong) = 0;

    virtual unsigned int stmt_errno(MYSQL_STMT *) = 0;

    virtual const char * stmt_error(MYSQL_STMT *) = 0;

    virtual int stmt_execute(MYSQL_STMT *) = 0;

    virtual int stmt_fetch(MYSQL_STMT *) = 0;

    virtual unsigned int stmt_field_count(MYSQL_STMT *) = 0;

    virtual MYSQL_STMT * stmt_init(MYSQL *) = 0;

    virtual my_ulonglong stmt_num_rows(MYSQL_STMT *) = 0;

    virtual unsigned long stmt_param_count(MYSQL_STMT *) = 0;

    virtual int stmt_prepare(MYSQL_STMT *, const char *, unsigned long) = 0;

    virtual MYSQL_RES * stmt_result_metadata(MYSQL_STMT *) = 0;

    virtual my_bool stmt_send_long_data(MYSQL_STMT * stmt , unsigned int par_number, const char * data, unsigned long len) = 0;

    virtual const char *  stmt_sqlstate(MYSQL_STMT *) = 0;

    virtual int stmt_store_result(MYSQL_STMT *) = 0;

    virtual int stmt_next_result(MYSQL_STMT *) = 0;

    virtual bool stmt_free_result(MYSQL_STMT *) = 0;
};

ACE_Refcounted_Auto_Ptr<MySQLCAPI, ACE_Lock> get_api_handle(const SQLString& name);

#endif