#include <iostream>
#include "Point.h"

using namespace std;

int main() {
   Point pt;

   cout << "Enter a point in the form (x, y):\n";
   cin >> pt; 

   if (!cin.fail()) {
      cout << "Point entered was: " << pt << endl;
   } else {
      cout << "\nInvalid data\n"; 
   }
}