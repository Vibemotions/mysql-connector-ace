#ifndef _SQL_PARAMETER_METADATA_H_
#define _SQL_PARAMETER_METADATA_H_

#include "sqlstring.h"

class ParameterMetaData {

public:
    enum {
        parameterModeIn,
        parameterModeInOut,
        parameterModeOut,
        parameterModeUnknown
    };

    enum {
        parameterNoNulls,
        parameterNullable,
        parameterNullableUnknown
    };

    virtual SQLString getParameterClassName(unsigned int param) = 0;

    virtual int getParameterCount() = 0;

    virtual int getParameterMode(unsigned int param) = 0;

    virtual int getParameterType(unsigned int param) = 0;

    virtual SQLString getParameterTypeName(unsigned int param) = 0;

    virtual int getPrecision(unsigned int param) = 0;

    virtual int getScale(unsigned int param) = 0;

    virtual int isNullable(unsigned int param) = 0;

    virtual int isSigned(unsigned int param) = 0;

protected:
    virtual ~ParameterMetaData() {}
};
#endif
