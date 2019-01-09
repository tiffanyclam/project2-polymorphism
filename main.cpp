#include <iostream>
#include "main.h"

int main() {
    try {
        string filename = "practice.txt";
        
        Bikes bikes;
        bikes.read(filename);
        bikes.print();
        
        cout << endl;
        cout << "Total Number of Gears: "
            << bikes.getTotalGears() << endl;
        cout << "Total Capacity of Delivery Bikes: "
        << bikes.getTotalCapacity() << endl;
    }
    
    catch (invalid_argument &e){
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (logic_error &e){
        cout << "Logic error: " << e.what() << endl;
    }
    catch (...){
        cout << "Uncaught exception" << endl;
    }
    
    return 0;
}
