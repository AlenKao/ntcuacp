#include <stdexcept>
#include "Package.h"

using namespace std;

Package::Package( const std::string &s_name, const std::string &s_addr, const std::string &s_city, 
    const std::string &s_state, int s_zip, const std::string &r_name, const std::string &r_addr, 
    const std::string &r_city, const std::string &r_state, int r_zip, double w, double cost) {

        setSenderName(s_name);
        setSenderAddress(s_addr);
        setSenderCity(s_city);
        setSenderState(s_state);
        setSenderZIP(s_zip);

        setRecipientName(r_name);
        setRecipientAddress(r_addr);
        setRecipientCity(r_city);
        setRecipientState(r_state);
        setRecipientZIP(r_zip);

        setWeight(w);
        setCostPerOunce(cost);
}

// Sender
void Package::setSenderName(const string &name) {
    senderName = name;
}
string Package::getSenderName() const {
    return senderName;
}

void Package::setSenderAddress(const string &addr) {
    senderAddress = addr;
}
string Package::getSenderAddress() const {
    return senderAddress;
}

void Package::setSenderCity(const string &city) {
    senderCity = city;
}
string Package::getSenderCity() const {
    return senderCity;
}

void Package::setSenderState(const string &state) {
    senderState = state;
}
string Package::getSenderState() const {
    return senderState;
}

void Package::setSenderZIP(int zip) {
    senderZIP = zip;
}
int Package::getSenderZIP() const {
    return senderZIP;
}

// Recipient
void Package::setRecipientName(const string &name) {
    recipientName = name;
}
string Package::getRecipientName() const {
    return recipientName;
}

void Package::setRecipientAddress(const string &addr) {
    recipientAddress = addr;
}
string Package::getRecipientAddress() const {
    return recipientAddress;
}

void Package::setRecipientCity(const string &city) {
    recipientCity = city;
}
string Package::getRecipientCity() const {
    return recipientCity;
}

void Package::setRecipientState(const string &state) {
    recipientState = state;
}
string Package::getRecipientState() const {
    return recipientState;
}

void Package::setRecipientZIP(int zip) {
    recipientZIP = zip;
}
int Package::getRecipientZIP() const {
    return recipientZIP;
}


void Package::setWeight(double w) {
    if (w > 0.0) {
        weight = w;
    } else {
        throw invalid_argument("Weight must be > 0.\n");
    }
}
double Package::getWeight() const {
    return weight;
}

void Package::setCostPerOunce(double cost) {
    if (cost > 0.0) {
        costPerOunce = cost;
    } else {
        throw invalid_argument("Cost per ounce must be > 0.\n");
    }
}
double Package::getCostPerOunce() const {
    return costPerOunce;
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}