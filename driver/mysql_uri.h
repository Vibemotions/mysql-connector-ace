#ifndef _MYSQL_URI_H_
#define _MYSQL_URI_H_

#include <aceconn/sqlstring.h>
#include <vector>

class ConnectionWrapper;

struct Host_Data;
using Host_List = std::vector<Host_Data>;
class MySQL_Uri {

private:
    Host_List host_list;
    SQLString schema;
    uint16_t default_port;

public:
    struct Host_Data {

    };

    MySQL_Uri();

    /*
        iterator over Host_list object
    */
    Host_List::iterator begin() { return host_list.begin(); }
    Host_List::iterator end() { return host_list.end(); }
    size_t size() const { return host_list.size(); }
};

#endif