// Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Date.h"
#include <iostream>
#include <sstream>

using namespace std;

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

//Validate 
bool Date::validateDate(int m, int d, int y) {
    if (m < 1 || m > 12 || d < 1) return false;
    int daysInMonth = lastDay(m, y);
    return d <= daysInMonth;
}


//Set date based on date validation. If no date provided, sets the default date.
void Date::setDate(int m, int d, int y) {
    if (validateDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    }
    else {
        month = 1;
        day = 1;
        year = 1900;
    }
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }


//Check stored date for leap year.
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

//Check for leap year in provided date.
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

//Check the last day of the month based on the stored month and year.
int Date::lastDay() const {
    return lastDay(month, year);
}


//Check the last day of the month based on provided month and year.
int Date::lastDay(int m, int y) const {
    switch (m) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(y) ? 29 : 28;
    default:
        return 31;
    }
}


//Display digits only date.
string Date::printNumeric() const {
    ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

//Display the date in American format.
string Date::printLong() const {
    const string months[] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December" };
    ostringstream oss;
    oss << months[month - 1] << " " << day << ", " << year;
    return oss.str();
}


//Display date in European format.
string Date::printEuropean() const {
    const string months[] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December" };
    ostringstream oss;
    oss << day << " " << months[month - 1] << " " << year;
    return oss.str();
}
