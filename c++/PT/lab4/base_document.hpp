#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <iomanip>

using namespace std;

class BaseDocument {
public:
    friend class DocumentManager;

    explicit BaseDocument(int type, bool dated)
        : type(type), has_date(dated), name(""), secondName("") {}

    virtual ~BaseDocument() {}

    virtual void          ask() = 0;

    virtual ostream& write (ostream& os) const = 0;
    virtual istream& read (istream& is) = 0;

    friend ostream& operator<< (ostream& os, const BaseDocument& doc) {
        doc.write(os);
        return os;
    }

    friend istream& operator>> (istream& is, BaseDocument& doc) {
        doc.read(is);
        return is;
    }

protected:
    const int type;
    bool has_date;
    string name;
    string secondName;
};

class BaseDatedDocument : public BaseDocument {
public:
    friend class DocumentManager;
    explicit BaseDatedDocument(int type)
        : BaseDocument(type, true), birth_date("") {}

protected:
    string birth_date;
};

#endif // DOCUMENT_H
