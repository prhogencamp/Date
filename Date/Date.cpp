// Date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Date.h"
#include <iostream>


using namespace std;

const int NumberArray::MAX_SIZE = 10;
const double NumberArray::DEFAULT_VALUE = 0.0;


NumberArray::NumberArray(int arraySize) {
	size = (arraySize > 0) ? arraySize : MAX_SIZE;
	numbers = new double[size];

	for (int i = 0; i < size; i++) {
		numbers[i] = 0.0;
	}
}
NumberArray::~NumberArray() {
	delete[] numbers;

}

void NumberArray::setNumber(int index, double value) {
	if (index >= 0 && index < size) {
		numbers[index] = value;
	}
	else {
		cerr << "Out of bounds";
	}
}

double NumberArray::getNumber(int index) const {
	if (index >= 0 && index < size) {
		return numbers[index];
	}
	else {
		cerr << "Out of bounds" << endl;
		return DEFAULT_VALUE;
	}
}

double NumberArray::findMin() const {
	if (size == 0) {
		cerr << "There is nothing in the array" << endl;
		return DEFAULT_VALUE;
	}

	double minValue = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] < minValue) {
			minValue = numbers[i];
		}
	}
	return minValue;
}
double NumberArray::findMax() const {
	if (size == 0) {
		cerr << "There is nothing in the array" << endl;
		return DEFAULT_VALUE;
	}
	double maxValue = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] > maxValue) {
			maxValue = numbers[i];
		}
	}
	return maxValue;
}

double NumberArray::calculateAverage() const {
	double sum = 0.0; 
	if (size == 0) {
		cerr << "The array is empty" << endl;
		return DEFAULT_VALUE; 
	}
	for (int i = 0; i < size; i++) {
		sum += numbers[i]; 
	}
	double average = sum / size; 
	return average; 
}


void NumberArray::printArray() const {
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

