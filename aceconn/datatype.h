#ifndef _DATATYPE_H_
#define _DATATYPE_H_

class DataType {
private:
    DataType();

public:
    enum {
        UNKNOWN = 0,
        BIT,
        TINYINT,
        SMALLINT,
        MEDIUMINT,
        INTEGER,
        BIGINT,
        REAL,
        DOUBLE,
        DECIMAL,
        NUMERIC,
        CHAR,
        BINARY,
        VARCHAR,
        VARBINARY,
        LONGVARCHAR,
        LONGVARBINARY,
        TIMESTAMP,
        DATE,
        TIME,
        YEAR,
        GEOMETRY,
        ENUM,
        SET,
        SQLNULL,
        JSON
    };
};

#endif
