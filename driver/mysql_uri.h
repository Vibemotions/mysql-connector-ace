#ifndef _MYSQL_URI_H_
#define _MYSQL_URI_H_

#include <aceconn/sqlstring.h>
#include <driver/common.h>
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
        Host_Data(SQLString name, uint16_t port, bool has_port = false) : 
            name(name),
            port(port),
            has_port(has_port),
            protocol(PROTOCOL_TYPE::PROTOCOL_TCP)
        {}

        Host_Data();

    private:
        SQLString name;
        uint16_t port;
        bool has_port;
        PROTOCOL_TYPE protocol;
    };

    MySQL_Uri();

    /*
        encapsulate functions of container vector for Host_List
    */
    Host_List::iterator begin() { return host_list.begin(); }
    Host_List::iterator end() { return host_list.end(); }
    size_t size() const { return host_list.size(); }

    void clear() { host_list.clear(); }

    void erase(Host_List::iterator it) { host_list.erase(it); }

    // void addHost(Host_Data host) { host_list.push_back(host); }
    void setHost(Host_Data host) { ; }
};

#endif