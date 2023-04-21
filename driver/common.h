using MYSQL_ROW = char**;
using my_socket = int;
#define SCRAMBLE_LENGTH 20
struct Vio;
#define MYSQL_VIO Vio*
#define MYSQL_ERRMSG_SIZE 512
#define SQLSTATE_LENGTH 5

enum class MYSQL_STATUS {
    MYSQL_STATUS_READY,
    MYSQL_STATUS_GET_RESULT,
    MYSQL_STATUS_USE_RESULT,
    MYSQL_STATUS_STMT_GET_RESULT
};

enum class RESULTSET_METADATA {
    RESULTSET_METADATA_NONE = 0,
    RESULTSET_METADATA_FULL = 1
};

struct LIST {
    LIST *prev, *next;
    void *data;
};

struct CHARSET_INFO {
    unsigned int number;   /* character set number              */
    unsigned int state;    /* character set state               */
    const char *csname;    /* character set name                */
    const char *name;      /* collation name                    */
    const char *comment;   /* comment                           */
    const char *dir;       /* character set directory           */
    unsigned int mbminlen; /* min. length for multibyte strings */
    unsigned int mbmaxlen; /* max. length for multibyte strings */
};

struct st_mysql_options {
    unsigned int connect_timeout, read_timeout, write_timeout;
    unsigned int port, protocol;
    unsigned long client_flag;
    char *host, *user, *password, *unix_socket, *db;
    struct Init_commands_array *init_commands;
    char *my_cnf_file, *my_cnf_group, *charset_dir, *charset_name;
    char *ssl_key;    /* PEM key file */
    char *ssl_cert;   /* PEM cert file */
    char *ssl_ca;     /* PEM CA file */
    char *ssl_capath; /* PEM directory of CA-s? */
    char *ssl_cipher; /* cipher to use */
    char *shared_memory_base_name;
    unsigned long max_allowed_packet;
    bool compress, named_pipe;
    /**
        The local address to bind when connecting to remote server.
    */
    char *bind_address;
    /* 0 - never report, 1 - always report (default) */
    bool report_data_truncation;

    /* function pointers for local infile support */
    int (*local_infile_init)(void **, const char *, void *);
    int (*local_infile_read)(void *, char *, unsigned int);
    void (*local_infile_end)(void *);
    int (*local_infile_error)(void *, char *, unsigned int);
    void *local_infile_userdata;
    struct st_mysql_options_extention *extension;
};

struct MYSQL {
NET net;                     /* Communication parameters */
    unsigned char *connector_fd; /* ConnectorFd for SSL */
    char *host, *user, *passwd, *unix_socket, *server_version, *host_info;
    char *info, *db;
    struct CHARSET_INFO *charset;
    MYSQL_FIELD *fields;
    struct MEM_ROOT *field_alloc;
    uint64_t affected_rows;
    uint64_t insert_id;      /* id if insert on table with NEXTNR */
    uint64_t extra_info;     /* Not used */
    unsigned long thread_id; /* Id for connection in server */
    unsigned long packet_length;
    unsigned int port;
    unsigned long client_flag, server_capabilities;
    unsigned int protocol_version;
    unsigned int field_count;
    unsigned int server_status;
    unsigned int server_language;
    unsigned int warning_count;
    struct st_mysql_options options;
    MYSQL_STATUS status;
    RESULTSET_METADATA resultset_metadata;
    bool free_me;   /* If free in mysql_close */
    bool reconnect; /* set to 1 if automatic reconnect */

    /* session-wide random string */
    char scramble[SCRAMBLE_LENGTH + 1];

    LIST *stmts; /* list of all statements */
    const struct MYSQL_METHODS *methods;
    void *thd;
    /*
        Points to boolean flag in MYSQL_RES  or MYSQL_STMT. We set this flag
        from mysql_stmt_close if close had to cancel result set of this object.
    */
    bool *unbuffered_fetch_owner;
    void *extension;
};

struct MYSQL_FIELD {
    char* name;
    char* table;
    char* db;
    char* defvalue;
    unsigned long length;
    unsigned long max_length;
    unsigned int name_length;
    unsigned int table_length;
    unsigned int db_length;
    unsigned int defvalue_length;
    unsigned int flags;
    unsigned int decimals;
    unsigned int charset;
    void* extension;
};

/*
    column types for MySQL
*/
enum class FIELD_TYPE {
    MYSQL_TYPE_DECIMAL,
    MYSQL_TYPE_TINY,
    MYSQL_TYPE_SHORT,
    MYSQL_TYPE_LONG,
    MYSQL_TYPE_FLOAT,
    MYSQL_TYPE_DOUBLE,
    MYSQL_TYPE_NULL,
    MYSQL_TYPE_TIMESTAMP,
    MYSQL_TYPE_LONGLONG,
    MYSQL_TYPE_INT24,
    MYSQL_TYPE_DATE,
    MYSQL_TYPE_TIME,
    MYSQL_TYPE_DATETIME,
    MYSQL_TYPE_YEAR,
    MYSQL_TYPE_VARCHAR,
    MYSQL_TYPE_BIT,
    MYSQL_TYPE_TIMESTAMP2,
    MYSQL_TYPE_INVALID = 243,
    MYSQL_TYPE_BOOL = 244,
    MYSQL_TYPE_JSON = 245,
    MYSQL_TYPE_NEWDECIMAL = 246,
    MYSQL_TYPE_ENUM = 247,
    MYSQL_TYPE_SET = 248,
    MYSQL_TYPE_TINY_BLOB = 249,
    MYSQL_TYPE_MEDIUM_BLOB = 250,
    MYSQL_TYPE_LONG_BLOB = 251,
    MYSQL_TYPE_BLOB = 252,
    MYSQL_TYPE_VAR_STRING = 253,
    MYSQL_TYPE_STRING = 254,
    MYSQL_TYPE_GEOMETRY = 255
};

struct NET {
    MYSQL_VIO vio;
    unsigned char* buff;
    unsigned char* buff_end;
    unsigned char* write_pos;
    unsigned char* read_pos;
    /**
        Set if we are doing several queries in one
        command ( as in LOAD TABLE ... FROM MASTER ),
        and do not want to confuse the client with OK at the wrong time
    */
    unsigned long remain_in_buf, length, buf_length, where_b;
    unsigned long max_packet, max_packet_size;
    unsigned int pkt_nr, compress_pkt_nr;
    unsigned int write_timeout, read_timeout, retry_count;
    int fcntl;
    unsigned int *return_status;
    unsigned char reading_or_writing;
    unsigned char save_char;
    bool compress;
    unsigned int last_errno;
    unsigned char error;
    /** Client library error message buffer. Actually belongs to struct MYSQL. */
    char last_error[MYSQL_ERRMSG_SIZE];
    /** Client library sqlstate buffer. Set along with the error message. */
    char sqlstate[SQLSTATE_LENGTH + 1];
    /**
        Extension pointer, for the caller private use.
        Any program linking with the networking library can use this pointer,
        which is handy when private connection specific data needs to be
        maintained.
        The mysqld server process uses this pointer internally,
        to maintain the server internal instrumentation for the connection.
    */
    void* extension;
};

struct MYSQL_BIND {
    unsigned long *length; /* output length pointer */
    bool* is_null;         /* Pointer to null indicator */
    void* buffer;          /* buffer to get/put data */
    /* set this if you want to track data truncations happened during fetch */
    bool* error;
    unsigned char *row_ptr; /* for the current data position */
    void (*store_param_func)(NET* net, struct MYSQL_BIND* param);
    void (*fetch_result)(struct MYSQL_BIND*, MYSQL_FIELD*, unsigned char** row);
    void (*skip_result)(struct MYSQL_BIND*, MYSQL_FIELD*, unsigned char** row);
    /* output buffer length, must be set when fetching str/binary */
    unsigned long buffer_length;
    unsigned long offset;              /* offset position for char/binary fetch */
    unsigned long length_value;        /* Used if length is 0 */
    unsigned int param_number;         /* For null count and error messages */
    unsigned int pack_length;          /* Internal length for packed data */
    // enum enum_field_types buffer_type; /* buffer type */
    FIELD_TYPE buffer_type;
    bool error_value;                  /* used if error is 0 */
    bool is_unsigned;                  /* set if integer type is unsigned */
    bool long_data_used;               /* If used with mysql_send_long_data */
    bool is_null_value;                /* Used if is_null is 0 */
    void* extension;
};

enum class PROTOCOL_TYPE {
    PROTOCOL_TCP,
    PROTOCOL_SOCKET,
    PROTOCOL_PIPE,
    // total num of supported protocol
    PROTOCOL_COUNT
};

enum class STATEMENT_OPTION {
    STMT_ATTR_UPDATE_MAX_LENGTH,
    STMT_ATTR_CURSOR_TYPE,
    STMT_ATTR_PREFETCH_ROWS
};

enum class CONNECTION_OPTION {
    MYSQL_OPT_CONNECT_TIMEOUT, MYSQL_OPT_COMPRESS, MYSQL_OPT_NAMED_PIPE,
    MYSQL_INIT_COMMAND, MYSQL_READ_DEFAULT_FILE, MYSQL_READ_DEFAULT_GROUP,
    MYSQL_SET_CHARSET_DIR, MYSQL_SET_CHARSET_NAME, MYSQL_OPT_LOCAL_INFILE,
    MYSQL_OPT_PROTOCOL, MYSQL_SHARED_MEMORY_BASE_NAME, MYSQL_OPT_READ_TIMEOUT,
    MYSQL_OPT_WRITE_TIMEOUT, MYSQL_OPT_USE_RESULT,
    MYSQL_REPORT_DATA_TRUNCATION, MYSQL_OPT_RECONNECT,
    MYSQL_PLUGIN_DIR, MYSQL_DEFAULT_AUTH,
    MYSQL_OPT_BIND,
    MYSQL_OPT_SSL_KEY, MYSQL_OPT_SSL_CERT,
    MYSQL_OPT_SSL_CA, MYSQL_OPT_SSL_CAPATH, MYSQL_OPT_SSL_CIPHER,
    MYSQL_OPT_SSL_CRL, MYSQL_OPT_SSL_CRLPATH,
    MYSQL_OPT_CONNECT_ATTR_RESET, MYSQL_OPT_CONNECT_ATTR_ADD,
    MYSQL_OPT_CONNECT_ATTR_DELETE,
    MYSQL_SERVER_PUBLIC_KEY,
    MYSQL_ENABLE_CLEARTEXT_PLUGIN,
    MYSQL_OPT_CAN_HANDLE_EXPIRED_PASSWORDS,
    MYSQL_OPT_MAX_ALLOWED_PACKET, MYSQL_OPT_NET_BUFFER_LENGTH,
    MYSQL_OPT_TLS_VERSION,
    MYSQL_OPT_SSL_MODE,
    MYSQL_OPT_RETRY_COUNT,
    MYSQL_OPT_GET_SERVER_PUBLIC_KEY,
    MYSQL_OPT_OPTIONAL_RESULTSET_METADATA,
    MYSQL_OPT_SSL_FIPS_MODE,
    MYSQL_OPT_TLS_CIPHERSUITES,
    MYSQL_OPT_COMPRESSION_ALGORITHMS,
    MYSQL_OPT_ZSTD_COMPRESSION_LEVEL,
    MYSQL_OPT_LOAD_DATA_LOCAL_DIR,
    MYSQL_OPT_USER_PASSWORD
};

struct MYSQL_RES {

};

struct MYSQL_STMT {

};