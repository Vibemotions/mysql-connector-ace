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

template<class T>
T* get() const {
    if (typeid(T).name() == typeid(void).name()) {
        return static_cast<T *>(cvptr);
    }

    if ((vTypeName == typeid(std::string).name() && typeid(T).name() == typeid(SQLString).name()) ||
        (vTypeName == typeid(SQLString).name() && typeid(T).name() == typeid(std::string).name()) ||
        (vTypeName == typeid(std::map<std::string, std::string>).name() && typeid(T).name() == typeid(std::map<SQLString, SQLString>).name()) ||
        (vTypeName == typeid(std::map<SQLString, SQLString>).name() && typeid(T).name() == typeid(std::map<std::string, std::string>).name()) ||
        (vTypeName == typeid(std::list<std::string>).name() && typeid(T).name() == typeid(std::list<SQLString>).name()) ||
        (vTypeName == typeid(std::list<SQLString>).name() && typeid(T).name() == typeid(std::list<std::string>).name())) {
        return static_cast<T *>(cvptr);
    }

    if (typeid(T).name() != vTypeName) {
        throw InvalidArgumentException("Variant Type does not match.");
    }

    return static_cast<T *>(cvptr);
}

protected:
    void* cvptr;
    SQLString vTypeName;
};


template<class T>
class VariantImpl : public BaseVariantImpl {

public:
    VariantImpl(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}

    VariantImpl(VariantImpl &that) : BaseVariantImpl(that) {
        copy_content(that);
    }

    VariantImpl& operator=(VariantImpl& that) {
        if (this != &that) {
            destroy_content();
            if (cvptr == nullptr) {
                copy_content(that);
            }
        }
        return *this;
    }

    virtual VariantImpl* Clone() {
        return new VariantImpl(*this);
    }

    ~VariantImpl() {
        destroy_content();
    }

private:
    void destroy_content() {
        T* tmp = static_cast<T *>(cvptr);
        if (tmp) {
            delete tmp;
            cvptr = nullptr;
        }
    }

    void copy_content(BaseVariantImpl& that) {
        cvptr = new T (*(static_cast<T *>(that.get<void>())));
    }
};


template<class T>
class VariantMap : public BaseVariantImpl {

public:
    VariantMap(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}

    VariantMap(VariantMap& that) : BaseVariantImpl(that) {
        if (this != &that) {
            copy_content(that);
        }
    }

    VariantMap& operator=(VariantMap& that) {
        if (this != &that) {
            destroy_content();
            copy_content(that);
        }
        return *this;
    }

    virtual VariantMap* Clone() {
        return new VariantMap(*this);
    }

    ~VariantMap() {
        destroy_content();
    }

private:
    void destroy_content() {
        T* tmp = static_cast<T *>(cvptr);
        if (tmp) {
            tmp->clear();
            delete tmp;
            cvptr = nullptr;
        }
    }

    void copy_content(VariantMap& var) {
        T* tmp = static_cast<T *>(var.cvptr);
        if (tmp) {
            cvptr = new T();
            typename T::const_iterator cit = tmp->begin();
            while (cit != tmp->end()) {
                (static_cast<T *>(cvptr))->insert(std::make_pair(SQLString(cit->first), SQLString(cit->second)));
                ++cit;
            }
        }
    }
};


template<class T>
class VariantList : public BaseVariantImpl {

public:
    VariantList(T i) : BaseVariantImpl(new T(i), typeid(i).name()) {}

    VariantList(VariantList& that) : BaseVariantImpl(that) {
        if (this != &that) {
            copy_content(that);
        }
    }

    VariantList& operator=(VariantList& that) {
        if (this != &that) {
            destroy_content();
            copy_content(that);
        }
    }

    virtual VariantList* Clone() {
        return new VariantList(*this);
    }

    ~VariantList() {
        destroy_content();
    }

private:
    void destroy_content() {
        T *tmp = static_cast<T *>(cvptr);
        if (tmp) {
            tmp->clear();
            delete tmp;
            cvptr = nullptr;
        }
    }

    void copy_content(VariantList& var) {
        T* tmp = static_cast<T *>(var.cvptr);
        if (tmp) {
            cvptr = new T();
            typename T::const_iterator cit = tmp->begin();
            while (cit != tmp->end()) {
                (static_cast<T *>(cvptr))->push_back(SQLString(*cit));
                ++cit;
            }
        }
    }
};


class Variant {

public:
    Variant(const int& i = 0) :
        variant(new VariantImpl<int>(i)) {}

    Variant(const double& i) :
        variant(new VariantImpl<double>(i)) {}

    Variant(const bool& i) :
        variant(new VariantImpl<bool>(i)) {}

    Variant(const char* i) :
        variant(new VariantImpl<SQLString>(i)) {}

    Variant(const std::string& i) :
        variant(new VariantImpl<SQLString>(i)) {}

    Variant(const SQLString& i) :
        variant(new VariantImpl<SQLString>(i)) {}

    Variant(const std::list<std::string>& i) :
        variant(new VariantList<std::list<std::string>>(i)) {}

    Variant(const std::list<SQLString>& i) :
        variant(new VariantList<std::list<SQLString>>(i)) {}

    Variant(const std::map<std::string, std::string>& i) :
        variant(new VariantMap<std::map<std::string, std::string>>(i)) {}

    Variant(const std::map<SQLString, SQLString>& i) :
        variant(new VariantMap<std::map<SQLString, SQLString>>(i)) {}

    Variant(const Variant& that) {
        if (this != &that) {
            variant = that.variant->Clone();
        }
    }

    Variant& operator=(const Variant& that) {
        if (this != &that) {
            delete variant;
            variant = that.variant->Clone();
        }
        return *this;
    }

    template<class T>
    T* get() const {
        return variant->get<T>();
    }

    ~Variant() {
        if (variant) {
            delete variant;
            variant = nullptr;
        }
    }

private:
    BaseVariantImpl* variant;
};
#endif
