#include <iostream>
#include <stdexcept>
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount(double bal, double tf) 
: Account{bal}{
    if (tf >= 0.0) {
        transactionFee = tf;
    } else {
        cout << "Transaction fee must be >= 0.\n";
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
        cout << "Debit amount exceeded account balance.\n";
        return false;
    }
}

void CheckingAccount::chargeFee() {
    cout << "&" << transactionFee << " transaction fee charged.\n";
    setBalance(getBalance() - transactionFee);
}