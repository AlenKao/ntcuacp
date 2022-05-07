#include <stdexcept>
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(double bal) {
    setBalance(bal);
}

void Account::credit(double c) {
    if (c > 0.0) {
        balance += c;
    } else {
        cout << "Credit must be > 0.\n";
    }
}

bool Account::debit(double d) {
    if (d <= getBalance()) {
        balance -= d;
        return true;
    } else {
        cout << "Debit amount exceeded account balance.\n";
        return false;
    }
}

void Account::setBalance(double b) {
    if (b >= 0.0) {
        balance = b;
    } else {
        cout << "Balance must be >= 0.0.\n";
    }
}
double Account::getBalance() {
    return balance;
}