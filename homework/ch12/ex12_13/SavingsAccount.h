#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class SavingsAccount : public Account {
public:
   SavingsAccount(double = 0.0, double = 0.0);

   double calculateInterest();

private:
   double interestRate; 
}; 

#endif