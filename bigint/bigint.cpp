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

ostream& BigInt::print(ostream &out) const {
  if (_is_negative) {
    out << '-';
  }
  return BigUint::print(out);
}

bool BigInt::is_negative() const {
    return _is_negative;
}

void BigInt::operator+=(const BigInt &b) {
    BigUint a1 = *this;
    BigUint b1 = b;
    if (b._is_negative) {
      if (is_negative()) {
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
      if (is_negative()) {
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
      *this = BigInt(0);
    if (b == BigInt(0))
      *this = BigInt(0);
    _is_negative = (_is_negative != b._is_negative);
    BigUint::operator*=((BigUint)b);
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

ostream& operator<< (std::ostream& stream, const BigInt& b){
   return b.print(stream);
}

bool operator== (const BigInt& a, const BigInt& b) {
  if (a.is_negative() != b.is_negative()) {
    return false;
  }
  return (BigUint)a == (BigUint)b;
}

bool operator< (const BigInt& a, const BigInt& b) {
  if (a.is_negative()) {
    if (b.is_negative())
      return (BigUint) a > (BigUint) b;
    else
      return true;
  }
  if (b.is_negative())
    return false;
  return (BigUint) a < (BigUint) b;
}

bool operator> (const BigInt& a, const BigInt& b) {
  if (a.is_negative()) {
    if (b.is_negative())
      return (BigUint) a < (BigUint) b;
    else
      return false;
  }
  if (b.is_negative())
    return true;
  return (BigUint) a > (BigUint) b;
}
