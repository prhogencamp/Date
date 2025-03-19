//This header defines the Date class and includes the prototypes.

#include <string>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    bool validateDate(int, int, int);
public:
    //setting default date
    Date(int = 1, int = 1, int = 1900);

    void setDate(int, int, int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool isLeapYear() const;
    bool isLeapYear(int) const;
    int lastDay() const;
    int lastDay(int, int) const;

    string printNumeric() const;
    string printLong() const;
    string printEuropean() const;
};


