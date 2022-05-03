#ifndef TWODAY_H
#define TWODAY_H

#include "Package.h"
using namespace std;

class TwoDayPackage : public Package {
public:
   TwoDayPackage( const std::string &, const std::string &, const std::string &, 
      const std::string &, int, const std::string &, const std::string &, const std::string &, 
      const std::string &, int, double = 0.0, double = 0.0, double = 0.0 );

   void setFlatFee( double ); 
   double getFlatFee() const; 

   double calculateCost() const; 
private:
   double flatFee; 
}; 

#endif
