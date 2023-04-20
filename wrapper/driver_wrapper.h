#ifndef _DRIVER_WRAPPER_H_
#define _DRIVER_WRAPPER_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/sqlstring.h>

class MySQLCAPI;
class ConnectionWrapper;

class DriverWrapper {

public:
    DriverWrapper(const SQLString& clientFileName);
    ~DriverWrapper();

    ConnectionWrapper& conn_init();

    DriverWrapper(const DriverWrapper&) = delete;
    DriverWrapper& operator=(const DriverWrapper&) = delete;
};

DriverWrapper* createDriverWrapper(const SQLString& clientFileName);

#endif