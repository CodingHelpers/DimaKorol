#ifndef STUDENTID_H
#define STUDENTID_H
#include "base_document.hpp"

enum {
    DocType_StudentID = 3
};

class StudentID : public BaseDocument {
public:
    explicit StudentID()
        : BaseDocument(DocType_StudentID, false), university(""), group(0) {}

    virtual void          ask();
    virtual ostream& write (ostream& os) const;
    virtual istream& read (istream& is);

protected:
    string university;
    int    group;
};

#endif // STUDENTID_H
