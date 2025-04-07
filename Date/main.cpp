#include "Date.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create a date object using the default constructor and display in first format
    Date d1;
    cout << "Testing Default Constructor: " << d1.printNumeric() << endl;

    // 2. Create a date object using the constructor with parameters and display in second format
    Date d2(2, 28, 2009);
    cout << "Testing Constructor with Valid Date: " << d2.printLong() << endl;

    // 3. Use setDate() function and display in the third format
    d1.setDate(3, 15, 2021);
    cout << "Testing setDate function: " << d1.printEuropean() << endl;

    // 4-6. Test invalid dates 
    d1.setDate(13, 45, 2018);
    cout << "Testing invalid month and day (13/45/2018): " << d1.printNumeric() << endl;

    d1.setDate(4, 31, 2000);
    cout << "Testing invalid day (4/31/2000): " << d1.printNumeric() << endl;

    d1.setDate(2, 29, 2009);
    cout << "Testing invalid leap year date (2/29/2009): " << d1.printNumeric() << endl;

    // 7-8. Test subtraction operator
    d1.setDate(4, 10, 2014);
    d2.setDate(4, 18, 2014);
    cout << "Days between 4/10/2014 and 4/18/2014: " << (d2 - d1) << " days" << endl;

    d1.setDate(2, 2, 2006);
    d2.setDate(11, 10, 2003);
    cout << "Days between 2/2/2006 and 11/10/2003: " << (d1 - d2) << " days" << endl;

    // 9-14. Test pre and post increment/decrement operators
    d1.setDate(2, 29, 2008);
    cout << "Before pre-decrement: " << d1.printNumeric() << endl;
    --d1;
    cout << "After pre-decrement (should be 1/31/2008): " << d1.printNumeric() << endl;

    ++d1;
    cout << "After pre-increment (should be 2/29/2008): " << d1.printNumeric() << endl;

    d1--;
    cout << "After post-decrement (should be 1/31/2008): " << d1.printNumeric() << endl;

    d1++;
    cout << "After post-increment (should be 2/29/2008): " << d1.printNumeric() << endl;

    d1.setDate(12, 31, 2024);
    cout << "Before post-increment: " << d1.printNumeric() << endl;
    d1++;
    cout << "After post-increment (should be 1/1/2025): " << d1.printNumeric() << endl;

    d1--;
    cout << "After post-decrement (should be 12/31/2024): " << d1.printNumeric() << endl;

    ++d1;
    cout << "After pre-increment (should be 1/1/2025): " << d1.printNumeric() << endl;

    --d1;
    cout << "After pre-decrement (should be 12/31/2024): " << d1.printNumeric() << endl;

    // 15-16. Test stream operators (user input/output)
    cout << "Enter a new date: ";
    cin >> d1;
    cout << "You entered: " << d1 << endl;

    return 0;
}