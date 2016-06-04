#include "studak.hpp"

ostream&
StudentID::write(ostream& os) const {
    return os << type << " "
              << name << " "
              << secondName << " "
              << university << " "
              << group << " ";
}

istream&
StudentID::read (istream& is) {
    return is >> name
              >> secondName
              >> university
              >> group;
}

void
StudentID::ask() {
    cout << "Name:         ";
    cin  >> name;
    cout << "Second Name:  ";
    cin  >> secondName;
    cout << "University:   ";
    cin  >> university;
    cout << "Group Number: ";
    cin  >> group;
}
