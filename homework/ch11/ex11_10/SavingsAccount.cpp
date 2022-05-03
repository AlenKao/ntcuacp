#include <stdexcept>
#include "SavingsAccount.h" 

using namespace std;

SavingsAccount::SavingsAccount(double bal, double i) 
: Account(bal), interestRate{i} {
    credit(calculateInterest());
}

double SavingsAccount::calculateInterest() {
    return getBalance() * interestRate/100.0;   
}