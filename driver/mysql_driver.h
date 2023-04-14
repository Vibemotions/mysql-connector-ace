#ifndef _MYSQL_DRIVER_H_
#define _MYSQL_DRIVER_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/driver.h>

class MySQL_Connection;

class DriverWrapper;

class MySQL_Driver : public Driver {
    
    ACE_Refcounted_Auto_Ptr<DriverWrapper, ACE_Lock> proxy;

public:
    MySQL_Driver();
    MySQL_Driver(const SQLString& clientLib);

    virtual ~MySQL_Driver();

    Connection* connect(SQLString& hostName,
                                SQLString& userName,
                                SQLString& password);

    Connection* connect(ConnectOptionsMap& options);

    int getMajorVersion();
    int getMinorVersion();
    int getPatchVersion();

    const SQLString& getName();

private:
    MySQL_Driver(const MySQL_Driver&);
    void operator=(MySQL_Driver&);
    friend MySQL_Connection;
};

#endif  // _MYSQL_DRIVER_H_