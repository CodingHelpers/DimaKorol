#ifndef INTERNATIONALID_H
#define INTERNATIONALID_H
#include "base_document.hpp"

enum {
    DocType_InternetionalID = 2
};

class InternationalPassport : public BaseDatedDocument {
public:
    explicit InternationalPassport()
        : BaseDatedDocument(DocType_InternetionalID), start_date(""), end_date("") {}

    virtual void          ask();
    virtual ostream& write (ostream& os) const;
    virtual istream& read (istream& is);

protected:
    string start_date;
    string end_date;
};

#endif // INTERNATIONALID_H
