#include <iostream> 
#include "Complex.h"
using namespace std;

int main() {
   Complex complex;

   cout << "Input a complex number in the form A + Bi:\n";
   cin >> complex; 

   if (!cin.fail()) { 
      cout << "Complex number entered was:\n" << complex << endl;
   } else {
      cout << "Invalid Data Entered\n";
   }
}