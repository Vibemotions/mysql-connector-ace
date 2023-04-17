#ifndef _MYSQL_RESULTBIND_H_
#define _MYSQL_RESULTBIND_H_

#include <ace/Auto_Ptr.h>
#include <ace/Refcounted_Auto_Ptr.h>
#include <aceconn/statement.h>
#include <aceconn/prepared_statement.h>
#include <aceconn/parameter_metadata.h>
#include <driver/common.h>
#include <mysql_debug.h>
#include <vector>

class StatementWrapper;

struct MySQL_Bind : public MYSQL_BIND {
    MySQL_Bind();
    MySQL_Bind(MySQL_Bind&&);
    MySQL_Bind(const MySQL_Bind&) = delete;
    ~MySQL_Bind();

    void setInt(int32_t value);
    void setDouble(double value);
    void setBoolean(bool value);
    void setString(const SQLString& value);
};

class MySQL_ResultBind {
    unsigned int num_fields;
    ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock> proxy;
    ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

public:
    ACE_Auto_Ptr<MySQL_Bind> res_bind;

    MySQL_ResultBind(ACE_Refcounted_Auto_Ptr<StatementWrapper, ACE_Lock>& stmt,
                     ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);

    ~MySQL_ResultBind();
};

class MySQL_AttrBind {
    std::vector<MySQL_Bind> bind;
    std::vector<const char*> names;
    int getBindPos(const SQLString& name);

public:
    MySQL_AttrBind();
    ~MySQL_AttrBind();

    int setQueryAttrInt(const SQLString& name, int32_t value);
    int setQueryAttrDouble(const SQLString &name, double value);
    int setQueryAttrBoolen(const SQLString &name, bool value);
    int setQueryAttrString(const SQLString &name, const SQLString& value);
    int setQueryAttrNull(const SQLString &name);

    void clearAttributes();

    MySQL_Bind* getBinds();
    const char** getNames();
};

#endif