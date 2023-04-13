typedef struct MYSQL_FIELD {
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

typedef char** MYSQL_ROW;