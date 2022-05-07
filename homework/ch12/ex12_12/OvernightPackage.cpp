#include <stdexcept>
#include "OvernightPackage.h"

using namespace std;

OvernightPackage::OvernightPackage(const std::string &s_name, const std::string &s_addr, const std::string &s_city, 
    const std::string &s_state, int s_zip, const std::string &r_name, const std::string &r_addr, 
    const std::string &r_city, const std::string &r_state, int r_zip, double w, double cost, double of) 
    : Package(s_name, s_addr, s_city, s_state, s_zip, r_name, r_addr, r_city, r_state, r_zip, w, cost) {
    setOvernightFeePerOunce(of);        
}

void OvernightPackage::setOvernightFeePerOunce(double of) {
    if (of >= 0.0) {
        overnightFeePerOunce = of;
    } else {
        throw invalid_argument("Overnight fee per ounce must be >= 0.\n");
    }
}
double OvernightPackage::getOvernightFeePerOunce() const {
    return overnightFeePerOunce;
}

double virtual OvernightPackage::calculateCost() const{
    return getWeight() * (getCostPerOunce() + overnightFeePerOunce);
}