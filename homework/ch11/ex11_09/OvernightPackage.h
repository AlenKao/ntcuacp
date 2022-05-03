#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include "Package.h"
using namespace std;

class OvernightPackage : public Package {
public:
   OvernightPackage( const std::string &, const std::string &, const std::string &, 
      const std::string &, int, const std::string &, const std::string &, const std::string &, 
      const std::string &, int, double = 0.0, double = 0.0, double = 0.0);
   
   void setOvernightFeePerOunce( double ); 
   double getOvernightFeePerOunce() const; 

   double calculateCost() const; 
private:
   double overnightFeePerOunce; 
}; 

#endif
