#include "factory.h"

Bike * BikeFactory::make(istream &in) throw (invalid_argument){
    Bike * bikePtr = NULL;
    char bikeType = ' ';
    
    in >> bikeType;
    in.putback(bikeType);
    
    if (in.good()){
        if (bikeType == 'D'){
            bikePtr = new Delivery;
        }
        else if (bikeType == 'U'){
            bikePtr = new Urban;
        }
        else
            throw invalid_argument("BikeFactory::make: Bike type not valid");
        bikePtr->read(in);
    }
    return bikePtr;
}

