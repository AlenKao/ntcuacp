#include <iostream>
#include <iomanip>
#include "Complex.h"

using namespace std;

ostream &operator<<(ostream& output, const Complex& c) {
    if (c.real == 0 && c.imaginary != 0) {
        output << c.imaginary << "i";
    } else if (c.real != 0 && c.imaginary == 0) {
        output << c.real;
    } else {
        output << c.real << showpos << c.imaginary << "i";
    }
    return output;
}

istream &operator>>(istream& input, Complex& c) {
    char sign;
    input >> c.real;
    input.ignore();
    input >> sign;
    input.ignore();
    input >> c.imaginary;
    if (sign == '-') {
        c.imaginary = -c.imaginary;
    }
    input.ignore();
    return input;
}

Complex::Complex(){}