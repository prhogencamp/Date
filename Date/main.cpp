#include "Date.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main() {

    // Test of the default constructor
    NumberArray defaultArray;
    cout << "Array of size 10\n";
    defaultArray.printArray();

    // Testing constructor with parameters
    NumberArray customArray(15);
    cout << "\nArray of size 15\n";
    customArray.printArray();



    // Inserting random numbers into array
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 100.0); 

    for (int i = 0; i < 15; i++) {
        double randomValue = dis(gen);
        customArray.setNumber(i, randomValue); 
    }

    customArray.printArray();

    // Testing for out-of-bounds
    customArray.setNumber(20, 99.9);

    // Testing a valid accessor
    cout << "Item at index 5: "
        << fixed << setprecision(1) << customArray.getNumber(5) << "\n";

    // Testing the out-of-bounds accessor
    cout << "\nOut of bounds. returning default:\n";
    cout << "Item at index 20 (out of bounds): "
        << customArray.getNumber(20) << "\n";

  
    // Test of the min, max, and average functions
    cout << "Min: "
        << customArray.findMin() << "\n";

    cout << "Max: "
        << customArray.findMax() << "\n";

    cout << "Average: "
        << customArray.calculateAverage() << "\n";

    return 0; 
}

