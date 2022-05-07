#ifndef TWODAY_H
#define TWODAY_H

#include "Package.h"

class TwoDayPackage : public Package {
public:
   TwoDayPackage(const std::string&, const std::string&, const std::string&, 
      const std::string&, int, const std::string&, const std::string&, const std::string&, 
      const std::string&, int, double, double, double);

   void setFlatFee(double);
   double getFlatFee() const;

   virtual double calculateCost() const; 
private:
   double flatFee;
}; 

#endif