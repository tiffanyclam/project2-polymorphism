#include "bike.h"

Bike::Bike(){
}

Bike::Bike(string id, string name, int gears) throw (invalid_argument){
    setID(id);
    setName(name);
    setGears(gears);
}

Bike::~Bike(){
}

int Bike::getGears() const {
    return gears;
}

string Bike::getID() const {
    return id;
}

string Bike::getName() const {
    return name;
}

void Bike::print(ostream &out) const {
    out << id << " " << name << " " << gears << " ";
}

void Bike::read(istream &in) throw (invalid_argument){
    char quote = ' ';

    in >> id;
    if (in.good()){
        setID(id);
        
        in >> quote;
        getline (in, name, '"');
        if (quote != '"')
            in.setstate(ios::failbit);
        else
            setName(name);
        in >> gears;
        setGears(gears);
    }
}

void Bike::setGears(int gears) throw (invalid_argument){
    if (gears < 1 || gears > 24)
        throw invalid_argument("Bike::setGears: gears not valid");
    this->gears = gears;
}

void Bike::setID(string id) throw (invalid_argument){
    if (id.length() != 3)
        throw invalid_argument("Bike::setID: ID not valid");
    if (id[0] < 'A' || id[0] > 'Z')
        throw invalid_argument("Bike::setID: ID not valid");
    if (id[1] < '0' || id[1] > '9' || id[2] < '0' || id[2] > '9')
        throw invalid_argument("Bike::setID: ID not valid");
    this->id = id;
}

void Bike::setName(string name){
    this->name = name;
}
