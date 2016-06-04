#include "passport.hpp"
#include <memory>

ostream&
Passport::write(ostream& os) const {
    return os << type << " "
              << name << " "
              << secondName << " "
              << father_name << " "
              << birth_date << " "
              << start_date << " ";
}

istream&
Passport::read(istream& is) {
    return is >> name
              >> secondName
              >> father_name
              >> birth_date
              >> start_date;
}

void
Passport::ask() {
    cout << "Name:         ";
    cin  >> name;
    cout << "Second Name:  ";
    cin  >> secondName;
    cout << "Father Name:  ";
    cin  >> father_name;
    cout << "Birth Date:   ";
    cin  >> birth_date;
    cout << "Start Date:   ";
    cin  >> start_date;
}
