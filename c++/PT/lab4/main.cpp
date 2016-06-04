#include <iostream>
#include "document_manager.hpp"
#include "passport.hpp"
#include "international_passport.hpp"
#include "studak.hpp"

using namespace std;

int main() {
    DocumentManager dm;

    dm.ask();

    cout << "\nDocs count: " << dm.count();
    cout << "\nDocuments:\n";
    dm.show();

    for(int i = 1; i <= 3; i++) {
        cout << "Documents with type " << i << ":" << endl;
        dm.show(i);
        cout << endl;
    }

    string date;
    cout << "Enter date: ";
    cin >> date;
    dm.show_date(date);

    cout << endl;

    string sname;
    cout << "Enter second name: ";
    cin >> sname;
    dm.show_name(sname);

    cout << "Documents saved to file \"docs.txt\"\n";
    dm.save("docs.txt");

    cout << "Deleting documents in list\n";
    for(int i = 1; i <= 3; i++) {
        dm.del(i);
        cout << endl;
    }

    cout << "Loading documents from file \"docs.txt\"\n";
    dm.load("docs.txt");

    cout << "\nDocuments count: " << dm.count();
    cout << "\nDocuments:\n";
    dm.show();
}
