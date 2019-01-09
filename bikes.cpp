#include "bikes.h"

Bikes::Bikes(){
}

Bikes::~Bikes(){
    for (unsigned int i = 0; i < bikes.size(); i++)
        delete bikes.at(i);
}

int Bikes::getTotalCapacity() const{
    int totalCapacity = 0;

    for (unsigned i = 0; i < bikes.size(); i++){
        Bike *b = bikes[i];
        if (typeid(*b) == typeid(Delivery)){
            Delivery *d = dynamic_cast<Delivery*>(b);
            int t = d->getCapacity();
            totalCapacity += t;
        }
    }
    return totalCapacity;
}

int Bikes::getTotalGears() const{
    int totalGears = 0;
    int t = 0;
    for (unsigned i = 0; i < bikes.size(); i++){
        Bike *b = bikes[i];
        if (typeid(*b) == typeid(Delivery)){
            Delivery *d = dynamic_cast<Delivery*>(b);
            t = d->getGears();
        }
        else if (typeid(*b) == typeid(Urban)){
            Urban *u = dynamic_cast<Urban*>(b);
            t = u->getGears();
        }
        totalGears += t;
    }
    return totalGears;
}

void Bikes::print(ostream &out) const{
    for (unsigned i = 0; i < bikes.size(); i++)
        bikes.at(i)->print(out);
}

void Bikes::read(string filename) throw (logic_error, invalid_argument){
    ifstream fin (filename.c_str());
    if (!fin)
        throw logic_error("Bikes::read: File not found");
    
    Bike *newBike = BikeFactory::make(fin);
    while (fin) {
        bikes.push_back(newBike);
        newBike = BikeFactory::make(fin);
    }
}

unsigned Bikes::size() const{
    return bikes.size();
}


