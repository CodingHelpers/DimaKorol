#include "international_passport.hpp"

ostream&
InternationalPassport::write(ostream& os) const {
    return os << type << " "
              << name << " "
              << secondName << " "
              << birth_date << " "
              << start_date << " "
              << end_date << " ";
}

istream&
InternationalPassport::read(istream& is) {
    return is >> name
              >> secondName
              >> birth_date
              >> start_date
              >> end_date;
}

void
InternationalPassport::ask() {
    cout << "Name:         ";
    cin  >> name;
    cout << "Second Name:  ";
    cin  >> secondName;
    cout << "Birth Date:   ";
    cin  >> birth_date;
    cout << "Start Date:   ";
    cin  >> start_date;
    cout << "End Date:     ";
    cin  >> end_date;
}
