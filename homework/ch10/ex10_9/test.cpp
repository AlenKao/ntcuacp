#include <iostream>
#include "Hugeinteger.h"

using namespace std;

int main() {
   HugeInteger n1{7654321};
   HugeInteger n2{7891234};
   HugeInteger n3{"99999999999999999999999999999"};
   HugeInteger n4{"1"};
   HugeInteger n5;

   cout << "n1 is " << n1 << "\nn2 is " << n2
      << "\nn3 is " << n3 << "\nn4 is " << n4
      << "\nn5 is " << n5 << "\n\n";

   n5 = n1 + n2;
   cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

   cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

   n5 = n1 + 9;
   cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

   n5 = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << n5 << "\n\n"; 

   n5 = n1*n2;
   cout << n1 << " * " << n2 << " = " << n5 << "\n\n"; 

   HugeInteger n6{256};
   HugeInteger n7{4};

   cout << n2 << " / " << n1 << " = " << (n2 / n1) << "\n\n";

   cout << n1 << " / " << n2 << " = " << (n1 / n2) << "\n\n";

   cout << n6 << " / " << n7 << " = " << (n6 / n7) << "\n\n";

   cout << n1 << " > " << n2 << " ? " << (n1 > n2 ? "true\n" : "false\n"); 

   cout << n2 << " < " << n3 << " ? " << (n2 < n3 ? "true\n" : "false\n"); 

   cout << n3 << " == " << n4 << " ? " << (n3 == n4 ? "true\n" : "false\n");

   cout << n1 << " >= " << n2 << " ? " << (n1 >= n2 ? "true\n" : "false\n");
}