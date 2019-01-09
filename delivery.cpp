#include "delivery.h"

Delivery::Delivery(){
}

Delivery::Delivery(string id, string name, int gears, int capacity) throw (invalid_argument)
    : Bike(id, name, gears) {
        setID(id);
        setCapacity(capacity);
}

int Delivery::getCapacity() const{
    return capacity;
}

void Delivery::print(ostream &out) const {
    Bike::print(out);
    out << capacity << endl;
}

void Delivery::read(istream &in) throw (invalid_argument){
    Bike::read(in);
    in >> capacity;
    setID(id);
    setCapacity(capacity);
}

void Delivery::setCapacity(int capacity) throw (invalid_argument){
    if (capacity < 1 || capacity > 120)
        throw invalid_argument("Delivery::setCapacity: capacity not valid");
    this->capacity = capacity;
}

void Delivery::setID(string id) throw (invalid_argument){
    Bike::setID(id);
    if (id.at(0) != 'D')
        throw invalid_argument("Delivery::setID: ID not valid");
    this->id = id;
}
