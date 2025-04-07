//This header defines the Date class and includes the prototypes.


#define DATE_H

#include <string>
using namespace std;



class Date {
private:
    int month, day, year; // creates month, day, and year variables
    bool validateDate(int m, int d, int y); //validates input integers are within bounds.
    bool isLeapYear(int y) const; //checks if the provided year (int y) is a leap year.
    int lastDay(int m, int y) const; //assigns the upper boundary for days in the month. Uses 'isLeapYear' return for assigning February's last day.

public:
    Date(int m = 1, int d = 1, int y = 1900); // Default constructor
    void setDate(int m, int d, int y); /* Mutator function to set private date integers after they have been validated by validateDate.
    If they are not valid dates, the default constructor is called.*/

    int getMonth() const; //gets month from private after setDate validates and sets month
    int getDay() const; //gets month from private after setDate validates and sets day
    int getYear() const; //gets year from private after setDate validates and sets year

    bool isLeapYear() const; //passes the year to the overloaded isLeapYear function.
    int lastDay() const; // passes the stored month and year to the overloaded lastDay function.

    string printNumeric() const; // print dates in mm/dd/yyyy form.
    string printLong() const; // print dates in Month Day, Year form.
    string printEuropean() const; // print dates in Day Month Year form.

    //Added operator overloads
    Date& operator++(); //prefix increment
    Date operator++(int); // postfix increment
    Date& operator--(); // prefix decrement
    Date operator --(int); // postfix decrement
    int operator-(const Date& other) const; // returns the difference between two dates
    friend ostream& operator<<(ostream& out, const Date& d); // allows output chaining of formatted dates
    friend istream& operator>>(istream& in, Date& d); // allows input chaining of dates in the MM DD YYYY format. 
};

