#include <stdexcept>
#include "TwoDayPackage.h"

using namespace std;

TwoDayPackage::TwoDayPackage(const std::string &s_name, const std::string &s_addr, const std::string &s_city, 
    const std::string &s_state, int s_zip, const std::string &r_name, const std::string &r_addr, 
    const std::string &r_city, const std::string &r_state, int r_zip, double w, double cost, double ff) 
    : Package(s_name, s_addr, s_city, s_state, s_zip, r_name, r_addr, r_city, r_state, r_zip, w, cost) {
    setFlatFee(ff);
}

void TwoDayPackage::setFlatFee(double ff) {
    if (ff >= 0) {
        flatFee = ff;
    } else {
        throw invalid_argument("Flat fee must be >= 0.\n");
    }
}
double TwoDayPackage::getFlatFee() const {
    return flatFee;
}

double virtual TwoDayPackage::calculateCost() const {
    return flatFee + Package::calculateCost();
}