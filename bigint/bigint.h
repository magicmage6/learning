#ifndef __BIG_INT_H
#define __BIG_INT_H

#include <iostream>
#include <string>

#include "biguint.h"


using namespace std;

class BigInt : public BigUint{
public:
  BigInt(int i);

  BigInt(const string& s);

  ostream& print(ostream& out) const;

  void operator+=(const BigInt &b);

  void operator*=(const BigInt &b);

  void operator/=(const BigInt &b);

  bool is_negative() const;

private:
  bool _is_negative;
};

ostream& operator<< (std::ostream& stream, const BigInt& b);

bool operator== (const BigInt& a, const BigInt& b);

bool operator< (const BigInt& a, const BigInt& b);

bool operator> (const BigInt& a, const BigInt& b);

BigInt operator+ (const BigInt& a, const BigInt& b);

BigInt operator* (const BigInt& a, const BigInt& b);

BigInt operator/ (const BigInt& a, const BigInt& b);

#endif