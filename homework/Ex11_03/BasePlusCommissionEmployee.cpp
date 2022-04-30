#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee( 
   const string &first, const string &last, const string &ssn, 
   double sales, double rate, double salary) 
   : commissionEmployee{first, last, ssn, sales, rate} {
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setFirstName(const string &first) {
    commissionEmployee.setFirstName(first);
}
string BasePlusCommissionEmployee::getFirstName() const {
    return commissionEmployee.getFirstName();
}

void BasePlusCommissionEmployee::setLastName(const string &last) {
    commissionEmployee.setLastName(last);
}
string BasePlusCommissionEmployee::getLastName() const {
    return commissionEmployee.getLastName();
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const string &ssn) {
    commissionEmployee.setSocialSecurityNumber(ssn);
}
string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return commissionEmployee.getSocialSecurityNumber();
} 

void BasePlusCommissionEmployee::setGrossSales(double sales) {
    commissionEmployee.setGrossSales(sales);
}
double BasePlusCommissionEmployee::getGrossSales() const {
    return commissionEmployee.getGrossSales();
}

void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    commissionEmployee.setCommissionRate(rate);
}
double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionEmployee.getCommissionRate();
} 

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary >= 0.0) {
        baseSalary = salary;
    } else {
        throw invalid_argument("Salary must be >= 0.0");
    }
}
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + commissionEmployee.earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried commission  employee: " << commissionEmployee.getFirstName() 
        << " " << commissionEmployee.getLastName() 
        << "\nsocial security number: " << commissionEmployee.getSocialSecurityNumber()
        << "\ngross sales: " << commissionEmployee.getGrossSales()
        << "\ncommission rate: " << commissionEmployee.getCommissionRate()
        << "\nbase salary: " << baseSalary; 
}
