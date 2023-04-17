typedef char** MYSQL_ROW;
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

struct Vio;
#define MYSQL_VIO Vio*
typedef int my_socket;
#define MYSQL_ERRMSG_SIZE 512
#define SQLSTATE_LENGTH 5

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