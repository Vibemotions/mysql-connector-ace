#ifndef _SQL_VARIANT_H_
#define _SQL_VARIANT_H_

#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <typeinfo>

#include "sqlstring.h"
#include "exception.h"

class BaseVariantImpl {

public:
    BaseVariantImpl (void* ptr, SQLString vtype) :
        cvptr(ptr),
        vTypeName(vtype)
    {}

    virtual ~BaseVariantImpl() {
        cvptr = NULL;
    }

    virtual BaseVariantImpl* Clone() = 0;

protected:
    void *cvptr;
    SQLString vTypeName;
};


template<class T>
class VariantImpl : public BaseVariantImpl {

public:
    VariantImpl(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}
};


template<class T>
class VariantMap : public BaseVariantImpl {

public:
    VariantMap(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}
};


template<class T>
class VariantList : public BaseVariantImpl {

public:
    VariantList(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}
};


class Variant {

private:
    BaseVariantImpl *variant;
};
#endif
