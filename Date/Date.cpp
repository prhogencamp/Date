#include "Date.h"
#include <iostream>
#include <sstream>

using namespace std;

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

bool Date::validateDate(int m, int d, int y) {
    if (m < 1 || m > 12 || d < 1) return false;
    return d <= lastDay(m, y);
}

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

bool Date::isLeapYear() const { return isLeapYear(year); }

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::lastDay() const { return lastDay(month, year); }

int Date::lastDay(int m, int y) const {
    switch (m) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(y) ? 29 : 28;
    default: return 31;
    }
}

string Date::printNumeric() const {
    ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

string Date::printLong() const {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    ostringstream oss;
    oss << months[month - 1] << " " << day << ", " << year;
    return oss.str();
}

string Date::printEuropean() const {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    ostringstream oss;
    oss << day << " " << months[month - 1] << " " << year;
    return oss.str();
}
Date& Date::operator++() {
    if (day == lastDay()) {
        day = 1;
        if (++month > 12) {
            month = 1;
            ++year;
        }
    }
    else {
        ++day;
    }
    return *this;
}
Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    if (day == 1) {
        if (--month < 1) {
            month = 12;
            --year;
        }
        day = lastDay(month, year);
    }
    else {
        --day;
    }
    return *this;
}
Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
    }

int Date::operator-(const Date& other) const {
    int days1 = year * 365 + day;
    for (int i = 1; i < month; i++) days1 += lastDay(i, year);

    int days2 = other.year * 365 + other.day;
    for (int i = 1; i < other.month; i++) days2 += lastDay(i, other.year);

    return abs(days1 - days2);
}

ostream& operator<<(ostream& out, const Date& d) {
    out << d.printLong();
    return out;
}

istream& operator>>(istream& in, Date& d) {
    int m, dVal, y;
    cout << "Enter month, day, and year as MM DD YYYY:";
    in >> m >> dVal >> y;
    d.setDate(m, dVal, y);
    return in;
}