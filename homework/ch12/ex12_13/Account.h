#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
   explicit Account(double = 0.0); 
   virtual void credit(double); 
   virtual bool debit(double); 
   void setBalance(double); 
   double getBalance(); 
   
private:
   double balance; 
}; 

#endif