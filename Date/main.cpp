#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    // Test for the default constructor
    Date date1;
    cout << "Default constructor: " << date1.printNumeric() << endl;

    // Testing valid parameterized constructor
    Date date2(2, 28, 2009);
    cout << "Valid date: " << date2.printNumeric() << endl;

    // Testing invalid month
    Date date3(45, 2, 2009);
    cout << "Invalid month: " << date3.printNumeric() << endl;

    // Testing invalid day
    Date date4(2, 29, 2009);
    cout << "Invalid day: " << date4.printNumeric() << endl;

    // Testing leap year
    Date date5(2, 29, 2008);
    cout << "Leap year: " << date5.printNumeric() << endl;

    // Testing print formats
    cout << "Print formats:" << endl;
    cout << date5.printNumeric() << endl;
    cout << date5.printLong() << endl;
    cout << date5.printEuropean() << endl;

    return 0;
}
