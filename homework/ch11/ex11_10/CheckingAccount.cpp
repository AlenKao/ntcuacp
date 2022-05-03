#include <iostream>
#include <stdexcept>
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount(double bal, double tf) 
: Account{bal}{
    if (tf >= 0.0) {
        transactionFee = tf;
    } else {
        throw invalid_argument("Transaction fee must be >= 0.\n");
    }
}

void CheckingAccount::credit(double c) {
    Account::credit(c);
    chargeFee();
}

bool CheckingAccount::debit(double d) {
    if (d + transactionFee <= getBalance()) {
        Account::debit(d);
        chargeFee();
        return true;
    } else {
        throw invalid_argument("Debit amount exceeded account balance.\n");
        return false;
    }
}

void CheckingAccount::chargeFee() {
    setBalance(getBalance() - transactionFee);
}