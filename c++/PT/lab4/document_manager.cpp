#include "document_manager.hpp"
#include "passport.hpp"
#include "international_passport.hpp"
#include "studak.hpp"
#include <fstream>
#include <iostream>

using namespace std;

DocumentManager::DocumentManager() {}
DocumentManager::~DocumentManager() {
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        delete *it;
    }
}

void
DocumentManager::ask() {
    int n;
    cout << "Enter number of your documents: ";
    cin  >> n;

    for(int i = 0; i < n; i++) {
        cout << endl << "Document #" << i << endl
             << DocType_ID << " - Passport" << endl
             << DocType_InternetionalID << " - International Passport" << endl
             << DocType_StudentID << " - Studak" << endl;

        int type;
        cin >> type;

        switch (type) {
        case DocType_ID:
            docs.push_back(new Passport);
        break;
        case DocType_InternetionalID:
            docs.push_back(new InternationalPassport);
        break;
        case DocType_StudentID:
            docs.push_back(new StudentID);
        break;
        }

        docs.back()->ask();
    }
}

void
DocumentManager::save(const string& filename) const {
    ofstream file(filename);
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        file << **it;
    }
}

void
DocumentManager::load(const string& filename) {
    ifstream file(filename);

    int type;
    while(file >> type) {
        switch (type) {
        case DocType_ID:
            docs.push_back(new Passport);
        break;
        case DocType_InternetionalID:
            docs.push_back(new InternationalPassport);
        break;
        case DocType_StudentID:
            docs.push_back(new StudentID);
        break;
        }
        docs.back()->read(file);
    }
}

void
DocumentManager::push(BaseDocument* doc) {
    docs.push_back(doc);
}

void
DocumentManager::del(int type) {
    for(auto it = docs.begin(); it != docs.end();) {
        if((*it)->type == type) {
            it = docs.erase(it);
        } else {
            ++it;
        }
    }
}

uint
DocumentManager::count() const {
    return static_cast<uint>(docs.size());
}

uint
DocumentManager::count(int type) const {
    uint cnt = 0;
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        if((*it)->type == type) {
            cnt++;
        }
    }
    return cnt;
}

void
DocumentManager::show() const {
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        cout << **it << endl;
    }
}

void
DocumentManager::show(int type) const {
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        if((*it)->type == type) {
             cout << **it << endl;
        }
    }
}

void
DocumentManager::show_name(const string& sname) const {
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        if((*it)->secondName == sname) {
             cout << **it << endl;
        }
    }
}

void
DocumentManager::show_date(const string& bd) const {
    for(auto it = docs.begin(); it != docs.end(); ++it) {
        if(!(*it)->has_date) continue;
        auto datedDocument = dynamic_cast<BaseDatedDocument*>(*it);
        if(datedDocument->birth_date == bd) {
             cout << **it << endl;
        }
    }
}
