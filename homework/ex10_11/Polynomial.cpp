#include <iostream> 
#include <iomanip> 
#include <string>
#include <sstream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial() 
:numberOfTerms{0}, exponents{}, coefficients{} {}

Polynomial Polynomial::operator+(const Polynomial& pol) const{
    Polynomial temp = *this;
    temp += pol;
    return temp;
}

Polynomial Polynomial::operator-(const Polynomial& pol) const {
    Polynomial temp = *this;
    temp -= pol;
    return temp;
}
Polynomial Polynomial::operator*(const Polynomial& pol) const {
    Polynomial temp;
    for (int i=0; i<this->numberOfTerms; i++) {
        for (int j=0; j<pol.numberOfTerms; j++) {
            int index = temp.numberOfTerms;
            temp.exponents[index] = this->exponents[i] + pol.exponents[j];
            temp.coefficients[index] = this->coefficients[i] * pol.coefficients[j];
            temp.numberOfTerms++;
            polynomialCombine(temp);
        }
    }
    
    return temp;
}

Polynomial& Polynomial::operator=(const Polynomial& pol) {
    this->exponents = pol.exponents;
    this->coefficients = pol.coefficients;
    this->numberOfTerms = pol.numberOfTerms;
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& pol) {
    for (int i=0; i<pol.numberOfTerms; i++) {   
        int index = this->numberOfTerms;
        this->coefficients[index] = pol.coefficients[i];
        this->exponents[index] = pol.exponents[i];
        this->numberOfTerms++;
        polynomialCombine(*this);
    }
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& pol) {
    for (int i=0; i<pol.numberOfTerms; i++) {
        int index = this->numberOfTerms;
        this->coefficients[index] = -pol.coefficients[i];
        this->exponents[index] = pol.exponents[i];
        this->numberOfTerms++;
        polynomialCombine(*this);
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& pol) {
    *this = *this * pol;
    return *this;
}

void Polynomial::enterTerms() {
    cin.clear();

    int ex, co;
    while (cin >> co >> ex) {
        if (co == 0) {
            cin.clear();   
            break;
        }

        this->exponents[numberOfTerms] = ex;
        this->coefficients[numberOfTerms] = co;

        numberOfTerms++;

        polynomialCombine(*this);
    }
}

string Polynomial::toString() const {
    ostringstream output;

    bool isfirstterm = true;

    for (int i=0; i<=numberOfTerms; i++) {
        if (coefficients[i] == 0) continue;
        if (coefficients[i] < 0) {
            output << "- ";
            if (coefficients[i] != -1) {
                output << -coefficients[i];
            } else {
                if (exponents[i] == 0) output << 1;
            }
        } else {
            if (!isfirstterm) {
                output << "+ ";
            }
            if (coefficients[i] != 1) {
                output << coefficients[i];
            } else {
                if (exponents[i] == 0) output << 1;
            }
        }
        
        if (exponents[i] != 0) {
            if (exponents[i] == 1) output << "x";
            else output << "x^" << exponents[i];
        } 

        output << " ";
        isfirstterm = false;
    }
    return output.str();
}

int Polynomial::getNumberOfTerms() const {
    return numberOfTerms;
} 

int Polynomial::getTermExponent(int i) const {
    return exponents[i]; 
}

int Polynomial::getTermCoefficient(int i) const {
    return coefficients[i];
}   

void Polynomial::setCoefficient(int i, int coefficient) {
    this->coefficients[i] = coefficient;
}

Polynomial::~Polynomial() {
    cout << "\n--- Polynomial delete ---\n";
} 

template<size_t Len>
void shift(array<int, Len>& arr, int s) {
    for (int i=s; i<Len-1; i++) {
        if (arr[i+1] != 0) arr[i] = arr[i+1];
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Polynomial::polynomialCombine(Polynomial& pol) {
    for (int i=pol.numberOfTerms-1; i>=0; i--) {
        for (int j=i-1; j>=0; j--) {
            if (pol.exponents[i] == pol.exponents[j]) {
                pol.coefficients[j] += pol.coefficients[i];
                pol.coefficients[i] = 0;
                pol.exponents[i] = 0;
                pol.numberOfTerms--;

                shift(pol.exponents, i);
                shift(pol.coefficients, i);
            }
        }
    }

    for (int i=0; i<pol.numberOfTerms; i++) {
        for (int j=i; j<pol.numberOfTerms-1; j++) {
            if (pol.exponents[j] < pol.exponents[j+1]) {
                swap(pol.exponents[j], pol.exponents[j+1]);
                swap(pol.coefficients[j], pol.coefficients[j+1]);
            }
        }
    }
}