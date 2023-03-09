#ifndef _SQL_WARNING_H_
#define _SQL_WARNING_H_

#include <stdexcept>
#include <string>
#include <memory>
#include "sqlstring.h"

class SQLWarning {

public:

    SQLWarning();

    virtual const SQLString &getMessage() const = 0;

    virtual const SQLString &getSQLState() const = 0;

    virtual int getErrorCode() const = 0;

    virtual const SQLWarning *getNextWarning() const = 0;

    virtual void setNextWarning(const SQLWarning * _next) = 0;

protected:

    virtual ~SQLWarning() {};

    SQLWarning(const SQLWarning&) {};

private:
    const SQLWarning &operator=(const SQLWarning& rhs);
};

#endif
