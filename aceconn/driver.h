#ifndef _SQL_DRIVER_H_
#define _SQL_DRIVER_H_

#include "connection.h"

class Driver {

protected:
    virtual ~Driver() {}

public:
    virtual Connection* connect(SQLString& hostName,
                                SQLString& userName,
                                SQLString& password) = 0;

    virtual Connection* connect(ConnectOptionsMap& options) = 0;

    virtual int getMajorVersion() = 0;
    virtual int getMinorVersion() = 0;
    virtual int getPatchVersion() = 0;

    virtual const SQLString& getName() = 0;
};

void check(const std::string&);
void check(const std::map<std::string, std::string>&);

inline static void check_lib() {
    check(std::string {});
    check(std::map<std::string, std::string> {});
}

extern "C"
{
    Driver* _get_driver_instance_by_name(const char* const clientlib);

    inline static Driver* get_driver_instance_by_name(const char* const clientlib) {
        check_lib();
        return _get_driver_instance_by_name(clientlib);
    }

    inline static Driver *get_driver_instance() {
        return get_driver_instance_by_name("");
    }
}

#endif
