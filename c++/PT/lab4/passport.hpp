#ifndef PASSPORT_H
#define PASSPORT_H
#include "base_document.hpp"
#include <time.h>
#include <memory>

enum {
    DocType_ID = 1
};

class Passport : public BaseDatedDocument {
public:
    explicit Passport()
        : BaseDatedDocument(DocType_ID), father_name(""), start_date("") {}

    virtual void          ask();
    virtual ostream& write (ostream& os) const;
    virtual istream& read (istream& is);

protected:
    string father_name;
    string start_date;
};


#endif // PASSPORT_H
