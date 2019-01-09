#include "urban.h"

Urban::Urban(){
}

Urban::Urban(string id, string name, int gears) throw (invalid_argument)
    : Bike(id, name, gears) {
        setID(id);
}

void Urban::print(ostream &out) const{
    Bike::print(out);
    out << endl;
}

void Urban::read(istream &in) throw (invalid_argument){
    Bike::read(in);
    setID(id); 
}

void Urban::setID(string id) throw (invalid_argument){
    Bike::setID(id);
    if (id.at(0) != 'U')
        throw invalid_argument("Urban::setID: ID not valid");
    this->id = id;
}
