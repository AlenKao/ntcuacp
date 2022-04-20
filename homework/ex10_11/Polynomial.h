#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <array>
#include <string>

class Polynomial {
public:
   static const int maxTerms = 100;

   Polynomial();
   Polynomial operator+(const Polynomial&) const; 
   Polynomial operator-(const Polynomial&) const; 
   Polynomial operator*(const Polynomial&) const; 
   Polynomial &operator=(const Polynomial&);
   Polynomial &operator+=(const Polynomial&);
   Polynomial &operator-=(const Polynomial&);
   Polynomial &operator*=(const Polynomial&);
   void enterTerms();
   std::string toString() const;
   int getNumberOfTerms() const; 
   int getTermExponent(int) const;
   int getTermCoefficient(int) const;
   void setCoefficient(int, int); 
   ~Polynomial(); 
private:
   size_t numberOfTerms{0};
   std::array<int, maxTerms> exponents{0}; 
   std::array<int, maxTerms> coefficients{0}; 
   static void polynomialCombine(Polynomial&);
};  

#endif 