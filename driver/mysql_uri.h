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
    
    private:
        SQLString _name;
        uint16_t _port;
        bool _has_port;
        PROTOCOL_TYPE _protocol;

    public:
        Host_Data(SQLString name, unsigned int port, bool has_port = false) : 
            _name(name),
            _port(port),
            _has_port(has_port),
            _protocol(PROTOCOL_TYPE::PROTOCOL_TCP)
        {}

        Host_Data();

        const SQLString& host() { return _name; }
        unsigned int port() { return _port; }
        bool hasPort() { return _has_port; }
        PROTOCOL_TYPE protocol() { return _protocol; }
        void setProtocol(PROTOCOL_TYPE p) { _protocol = p; }

        void setHost(const SQLString& name, uint16_t port) {
            setProtocol(PROTOCOL_TYPE::PROTOCOL_TCP);
            _name = name;
            _port = port;
            _has_port = true;
        }

        void setHost(const SQLString& name) {
            setProtocol(PROTOCOL_TYPE::PROTOCOL_TCP);
            _name = name;
        }

        void setPort(uint16_t port) {
            setProtocol(PROTOCOL_TYPE::PROTOCOL_TCP);
            _port = port;
            _has_port = true;
        }
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

    void setSchema(const SQLString& sch) { schema = sch; }
    SQLString getSchema() { return schema; }

    void setDefaultPort(uint16_t port) { default_port = port; }
    uint16_t getDefaultPort() { return default_port; }
};

bool tcpProtocol(Host_Data& host_data);
bool parseUri(const SQLString& str, MySQL_Uri& uri);

#endif