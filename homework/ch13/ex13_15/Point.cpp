#include <iostream>
#include "Point.h"

using namespace std;

ostream &operator<<(ostream& output, const Point& p) {
    output << "(" << p.xCoordinate << ", " << p.yCoordinate << ")";
    return output;
}

istream &operator>>(istream& input, Point& p) {
    input.ignore();
    input >> p.xCoordinate;
    input.ignore(2);
    input >> p.yCoordinate;
    input.ignore();
    return input;
} 