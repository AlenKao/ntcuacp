#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> 
#include "CommissionEmployee.h" 

class BasePlusCommissionEmployee {
public:
   BasePlusCommissionEmployee( const std::string &, const std::string &, 
      const std::string &, double = 0.0, double = 0.0, double = 0.0 );
   
   void setFirstName( const std::string & ); 
   std::string getFirstName() const; 

   void setLastName( const std::string & );
   std::string getLastName() const; 

   void setSocialSecurityNumber( const std::string & ); 
   std::string getSocialSecurityNumber() const; 

   void setGrossSales( double ); 
   double getGrossSales() const; 

   void setCommissionRate( double ); 
   double getCommissionRate() const; 

   void setBaseSalary( double ); 
   double getBaseSalary() const;

   double earnings() const; 
   void print() const; 
   
private:
   double baseSalary; 
   CommissionEmployee commissionEmployee; 
}; 

#endif
