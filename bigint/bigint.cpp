#include <iostream>
#include <string>

#include "bigint.h"

using namespace std;

string remove_sign(const string& s) {
  if (s[0] == '-')
    return s.substr(1);
  return s;
}

BigInt::BigInt(const int i) : BigUint(abs(i)) {
  if (i < 0) {
    _is_negative = true;
  } else {
    _is_negative = false;
  }
}

BigInt::BigInt(const string& s) : BigUint(remove_sign(s)) {
  BigUint a;
  bool negative;
  if (s[0] == '-') {
    _is_negative = true;
  } else {
    _is_negative = false;
  }
}

void BigInt::operator+=(const BigInt &b) {
    BigUint a1 = *this;
    BigUint b1 = b;
    if (b._is_negative) {
      if (_is_negative) {
        _is_negative = true;
        BigUint::operator+=(b1);
      } else {
        if (a1 < b1) {
          _is_negative = true;
          BigUint::operator=(b1 - a1);
        } else {
          _is_negative = false;
          BigUint::operator-=(b1);
        }
      }
    } else {
      if (_is_negative) {
        if (a1 > b1) {
          _is_negative = true;
          BigUint::operator-=(b1);
        } else {
          _is_negative = false;
          BigUint::operator=(b1 - a1);
        }
      } else {
        _is_negative = false;
        BigUint::operator+=(b1);
      }
    }
}

void BigInt::operator*=(const BigInt &b) {
    if (*this == BigInt(0))
      return;
    if (b == BigInt(0))
      *this = BigInt(0);
    _is_negative = (_is_negative != b._is_negative);
    BigUint::operator*=((BigUint)b);
}

void BigInt::operator/=(const BigInt &b) {
    if (*this == BigInt(0))
      return;
    _is_negative = (_is_negative != b._is_negative);
    BigUint::operator/=((BigUint)b);
}

int BigInt::compare(const BigInt &b) const {
  if (_is_negative) {
    if (b._is_negative) {
      return -BigUint::compare((BigUint)b);
    } else {
      return -1;
    }
  } else {
    if (b._is_negative) {
      return 1;
    } else {
      return BigUint::compare((BigUint)b);
    }
  }
}

BigInt operator+ (const BigInt& a, const BigInt& b) {
  BigInt sum = a;
  sum += b;
  return sum;
}

BigInt operator* (const BigInt& a, const BigInt& b) {
  BigInt product = a;
  product *= b;
  return product;
}

BigInt operator/ (const BigInt& a, const BigInt& b) {
  BigInt quotation = a;
  quotation /= b;
  return quotation;
}

ostream& operator<< (std::ostream& stream, const BigInt& b){
   if (b < BigInt(0)) {
    stream << '-';
  }
  stream << (BigUint)b;
  return stream;
}

bool operator== (const BigInt& a, const BigInt& b) {
  return (a.compare(b) == 0);
}

bool operator< (const BigInt& a, const BigInt& b) {
  return (a.compare(b) < 0);
}

bool operator> (const BigInt& a, const BigInt& b) {
  return (a.compare(b) > 0);
}
