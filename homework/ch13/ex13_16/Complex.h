#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream> 
using namespace std;

class Complex {
   friend ostream &operator<<(ostream&, const Complex&);
   friend istream &operator>>(istream&, Complex&);

public:
   Complex(); 
private:
   int real;
   int imaginary;
}; 

#endif