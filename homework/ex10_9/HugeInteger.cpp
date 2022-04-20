#include <cctype> 
#include "Hugeinteger.h" 

using namespace std;

ostream& operator<< (ostream& output, const HugeInteger& item) {
   bool isfirstdigit = 0, nobit = 1;

   for (int i=0; i<40; i++) {
      if (item.integer[i] != 0) { 
         isfirstdigit = 1;
      }

      if (isfirstdigit) {
         output << item.integer[i];
         nobit = 0;
      }
   }
   if (nobit) output << 0;
   return output;
}

HugeInteger::HugeInteger(long value) { 
   for (int j{digits - 1}; value != 0 && j >= 0; j--) {
      integer[j] = value % 10;
      value /= 10;
   }
}

HugeInteger::HugeInteger(const string& number) {
   int length = number.length();

   for (int j{digits - length}, k{0}; j < digits; ++j, ++k) {
      if (isdigit(number[k])) {
         integer[j] = number[k] - '0';
      }
   }
} 

// +
HugeInteger HugeInteger::operator+ (const HugeInteger& num) const{
   int carry = 0;
   HugeInteger temp;

   for (int i = digits-1; i >= 0; i--) {
      temp.integer[i] += (this->integer[i] + num.integer[i] + carry) % 10;

      if (num.integer[i] + this->integer[i] + carry > 9) carry = 1;
      else carry = 0;
   }
   return temp;
}

HugeInteger HugeInteger::operator+ (int num) const{
   return *this + HugeInteger(num);
}

HugeInteger HugeInteger::operator+ (const string& num) const{
   return *this + HugeInteger(num);
}

// - (no negative ><)
HugeInteger HugeInteger::operator-(const HugeInteger& num) const{
   HugeInteger temp;
   int carry = 0;

   for (int i=digits-1; i>=0; i--) {
      if (this->integer[i] - carry - num.integer[i] >= 0) {
         temp.integer[i] = (this->integer[i] - num.integer[i] - carry);
         carry = 0;
      } else {
         temp.integer[i] = (10 - carry - num.integer[i] + this->integer[i]);
         carry = 1;
      }
   }
   return temp;
}

HugeInteger HugeInteger::operator-(int num) const{
   return *this - HugeInteger(num);
}

HugeInteger HugeInteger::operator-(const string& num) const{
   return *this - HugeInteger(num);
}

// *
HugeInteger HugeInteger::operator*(const HugeInteger& num) const {
   HugeInteger temp;

   for (int i=digits-1; i>=0; i--) {
      int index = i, carry = 0;
      for (int j=digits-1; j>=0, index>=0; j--, index--) {
         temp.integer[index] += (this->integer[j] * num.integer[i]) + carry; 

         carry = temp.integer[index] / 10;
         temp.integer[index] %= 10;
      }
   }
   return temp;
}

HugeInteger HugeInteger::operator*(int num) const {
   return *this * HugeInteger(num);
}

HugeInteger HugeInteger::operator*(const std::string& num) const {
   return *this * HugeInteger(num);
}

// /
HugeInteger HugeInteger::operator/(const HugeInteger& num) const {
   if (*this < num) return 0;

   HugeInteger d{*this};
   HugeInteger res;
   while (d >= num) {
      d = (d - num);
      res = (res + 1);     
   }
   return res;
}

HugeInteger HugeInteger::operator/(int num) const {
   return *this / HugeInteger(num);
}

HugeInteger HugeInteger::operator/(const std::string& num) const {
   return *this / HugeInteger(num);
}  

// ==
bool HugeInteger::operator==(const HugeInteger& num) const {
   for (int i=digits-1; i>=0; i--) {
      if (this->integer[i] != num.integer[i]) return false;
   }
   return true;
}

bool HugeInteger::operator==(int num) const {
   return *this == HugeInteger(num);
}

bool HugeInteger::operator==(const std::string& num) const {
   return *this == HugeInteger(num);
} 

// !=
bool HugeInteger::operator!=(const HugeInteger& num) const {
   return !((*this) == num);
}

bool HugeInteger::operator!=(int num) const {
   return *this != HugeInteger(num);
}

bool HugeInteger::operator!=(const std::string& num) const {
   return *this != HugeInteger(num);
}

// <
bool HugeInteger::operator<(const HugeInteger& num) const {
   for (int i=0; i<=digits-1; i++) {
      if (this->integer[i] == num.integer[i]) continue;
      else {
         if (this->integer[i] < num.integer[i]) return true;
         else return false;
      }
   }
   return false;
}

bool HugeInteger::operator<(int num) const {
   return *this < HugeInteger(num);
}

bool HugeInteger::operator<(const std::string& num) const {
   return *this < HugeInteger(num);
}

// <= 
bool HugeInteger::operator<=(const HugeInteger& num) const {
   return (*this == num || *this < num);
}

bool HugeInteger::operator<=(int num) const {
   return *this <= HugeInteger(num);
}

bool HugeInteger::operator<=(const std::string& num) const {
   return *this <= HugeInteger(num);
}

// >
bool HugeInteger::operator>(const HugeInteger& num) const {
   for (int i=0; i<=digits-1; i++) {
      if (this->integer[i] == num.integer[i]) continue;
      else {
         if (this->integer[i] > num.integer[i]) return true;
         else return false;
      }
   }
   return false;

}

bool HugeInteger::operator>(int num) const {
   return *this > HugeInteger(num);
}

bool HugeInteger::operator>(const std::string& num) const {
   return *this > HugeInteger(num);
}

// >=
bool HugeInteger::operator>=(const HugeInteger& num) const {
   return (*this == num || *this > num);
}

bool HugeInteger::operator>=(int num) const {
   return *this >= HugeInteger(num);
}

bool HugeInteger::operator>=(const std::string& num) const {
   return *this >= HugeInteger(num);
}