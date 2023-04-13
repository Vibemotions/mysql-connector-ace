#ifndef _MYSQL_DEBUG_H_
#define _MYSQL_DEBUG_H_

#include <ace/Refcounted_Auto_Ptr.h>
#include <stack>
#include <driver/common.h>

#define CPP_ENTER(msg)
#define CPP_INFO(msg)
#define CPP_ERR(msg)

class MySQL_DebugEnterEvent;

class MySQL_DebugLogger {
    std::stack<const MySQL_DebugEnterEvent*> callstack;
    int tracing;

    enum class TRACE_MODE {
        NO_TRACE,
        NORMAL_TRACE
    };

public:
    MySQL_DebugLogger();
    virtual ~MySQL_DebugLogger();

    void enableTracing();
    
    void disableTracing();
    
    void enter(const MySQL_DebugEnterEvent* object);

    void leave(const MySQL_DebugEnterEvent* object);

    void log(const char* const type, const char* const message);

private:
    MySQL_DebugLogger(const MySQL_DebugLogger&);
    void operator=(MySQL_DebugLogger&);
};

class MySQL_DebugEnterEvent {

public:
    unsigned int line;
    const char* const file;
    const char* const func;
    const ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock> logger;

    MySQL_DebugEnterEvent(unsigned int line,
                          const char* const file,
                          const char* const func,
                          ACE_Refcounted_Auto_Ptr<MySQL_DebugLogger, ACE_Lock>& logger);
    ~MySQL_DebugEnterEvent();

};

#endif  // _MYSQL_DEBUG_H_