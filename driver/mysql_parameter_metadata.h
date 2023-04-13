#ifndef _MYSQL_PARAMETER_METADATA_H_
#define _MYSQL_PARAMETER_METADATA_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/parameter_metadata.h>

class StatementWrapper;

class MySQL_ParameterMetaData : ParameterMetaData {
    
    unsigned int param_count;

public:
    MySQL_ParameterMetaData(ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock>& stmt);

    virtual ~MySQL_ParameterMetaData();

    virtual SQLString getParameterClassName(unsigned int param);

    virtual int getParameterMode(unsigned int param);

    virtual int getParameterType(unsigned int param);

    virtual SQLString getParameterTypeName(unsigned int param);

    virtual int getParameterCount();

    virtual int getPrecision(unsigned int param);

    virtual int getScale(unsigned int param);

    virtual int isNullable(unsigned int param);

    virtual int isSigned(unsigned int param);

private:
    /*
        prevent use of these
    */
    MySQL_ParameterMetaData(const MySQL_ParameterMetaData&);
    void operator=(MySQL_ParameterMetaData&);
};

#endif  // _MYSQL_PARAMETER_METADATA_H_