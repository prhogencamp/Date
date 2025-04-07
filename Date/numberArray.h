//This header defines the numberArray class and includes the prototypes.

#include <string>

using namespace std;

class NumberArray {
private:
    double* numbers;
    int size;
    double sum;
    static const int MAX_SIZE;
    static const double DEFAULT_VALUE;
    


public:
    NumberArray(int size = MAX_SIZE);
    ~NumberArray();

    //Member Function prototypes
    void setNumber(int index, double value);
    double getNumber(int index) const;
    double findMax() const;
    double findMin() const;
    double calculateAverage() const;
    void printArray() const;
    


};
