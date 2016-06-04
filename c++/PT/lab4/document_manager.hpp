#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include "base_document.hpp"
#include <string>
#include <list>
#include <memory>

class DocumentManager {
public:
    DocumentManager();
   ~DocumentManager();

    void ask();

    void save(const string& filename) const;
    void load(const string& filename);

    void push(BaseDocument* doc);
    void del(int type);

    uint count() const;
    uint count(int type) const;

    void show() const;
    void show(int type) const;
    void show_name(const string& sname) const;
    void show_date(const string& bd) const;

private:
    list<BaseDocument*> docs;
};

#endif // DOCUMENTMANAGER_H
