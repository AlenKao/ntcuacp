#include <stdexcept>
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(double bal, double i) 
: Account(bal), interestRate{i} {}

double SavingsAccount::calculateInterest() {
    return getBalance() * interestRate;   
}