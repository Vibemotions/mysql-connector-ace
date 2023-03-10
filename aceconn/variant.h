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

    virtual VariantImpl* Clone() {
        return new VariantImpl(*this);
    }

private:
    void destroy_content() {

    }

    void copy_content(BaseVariantImpl& that) {

    }
};


template<class T>
class VariantMap : public BaseVariantImpl {

public:
    VariantMap(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}

    ~VariantMap() {

    }

private:
    void destroy_content() {

    }

    void copy_content(VariantMap& var) {

    }
};


template<class T>
class VariantList : public BaseVariantImpl {

public:
    VariantList(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}

    ~VariantList() {

    }

private:
    void destroy_content() {

    }

    void copy_content(VariantList& var) {

    }
};


class Variant {

public:
    Variant(const int &i = 0) :
        variant(new VariantImpl< int >(i)) {}

    ~Variant() {
        if (variant) {
            delete variant;
            variant = 0;
        }
    }

private:
    BaseVariantImpl *variant;
};
#endif
