#include <algorithm>
#include <iostream>
#include <string>

#include "biguint.h"

using namespace std;

namespace {
  int slow_division(const BigUint& a, const BigUint& b) {
    int cnt = 0;
    BigUint c = b;
    while (!(c > a)) {
      c += b;
      ++cnt;
    }
    return cnt;
  }
}

BigUint::BigUint(const int i) {
  int d = i;
  while (d > 0) {
    _data.push_back(d % 10);
    d /= 10;
  }
}

BigUint::BigUint(const string s) {
  for (int i = s.size() - 1; i >= 0; --i) {
    _data.push_back(s[i] - '0');
  } 
}

int BigUint::size() const {
  int i;
  for (i = _data.size() - 1; i >= 0; --i) {
    if (_data[i] != 0)
      break;
  }
  return i + 1;
}


ostream& BigUint::print(ostream &out) const {
  if (size() == 0) {
    out << '0';
  }
  for (int i = size() - 1; i >= 0; --i) {
    out << _data[i];
  } 
  return out;
}

int BigUint::operator[](const int i) const {
  if (i >= _data.size() || i < 0)
    return 0;
  return _data[i];
}

void BigUint::operator+=(const BigUint& b) {
  const int new_size = std::max(size(), b.size()) + 1;
  _data.resize(new_size);
  int carry = 0;
  for (int i = 0; i < new_size; ++i) {
    int d = (*this)[i] + b[i] + carry;
    if (d >= 10) {
      _data[i] = d - 10;
      carry = 1;
    } else {
      _data[i] = d;
      carry = 0;
    }
  }
}

void BigUint::operator-=(const BigUint& b) {
  if (*this < b) {
    _data.clear();
    return;
  }
  int carry = 0;
  for (int i = 0; i < size(); ++i) {
    int d = (*this)[i] - b[i] - carry;
    if (d < 0) {
      _data[i] = d + 10;
      carry = 1;
    } else {
      _data[i] = d;
      carry = 0;
    }
  }
}

void BigUint::operator*=(const int b) {
  if (b == 0) {
    _data.clear();
    return;
  }
  const BigUint a = *this;
  _data.clear();
  for (int i = 0; i < b; ++i)
    (*this) += a;
}

void BigUint::operator*=(const BigUint& b) {
  const BigUint a = *this;
  BigUint product;
  for (int i = 0; i < b.size(); ++i) {
    BigUint temp = a;
    temp *= b[i];
    product += (temp << i);
  }
  *this = product;
}

void BigUint::operator/=(const BigUint& b) {
  *this = (*this) / b;
}

void BigUint::rs(const int n) {
  if (n <= 0)
    return;
  int i;
  int orig_size = size();
  for (i = 0; i < orig_size - n; ++i) {
    _data[i] = _data[i + n];
  }
  for (; i < orig_size; ++i) {
    _data[i] = 0;
  }
}

void BigUint::ls(const int n) {
  if (n <= 0)
    return;
  int orig_size = size();
  int new_size = orig_size + n;
  _data.resize(new_size);
  for (int i = new_size - 1; i >= n; --i) {
    _data[i] = _data[i - n];
  }
  for (int i = 0; i < n; ++i) {
    _data[i] = 0;
  }
}

bool operator== (const BigUint& a, const BigUint& b) {
  if (a.size() != b.size())
    return false;
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i])
      return false;
  return true;
}

bool operator> (const BigUint& a, const BigUint& b) {
  if (a.size() > b.size())
    return true;
  if (a.size() < b.size())
    return false;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] > b[i])
      return true;
    if (a[i] < b[i])
      return false;
  }
  return false;
}

bool operator< (const BigUint& a, const BigUint& b) {
  if (a.size() > b.size())
    return false;
  if (a.size() < b.size())
    return true;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] > b[i])
      return false;
    if (a[i] < b[i])
      return true;
  }
  return false;
}

BigUint operator+ (const BigUint& a, const BigUint& b) {
  BigUint sum = a;
  sum += b;
  return sum;
}

BigUint operator- (const BigUint& a, const BigUint& b) {
  BigUint sum = a;
  sum -= b;
  return sum;
}

BigUint operator* (const BigUint& a, const BigUint& b) {
  BigUint product = a;
  product *= b;
  return product;
}

BigUint operator% (const BigUint& a, const BigUint& b) {
  return a - (a / b) * b;
}

BigUint operator/ (const BigUint& a, const BigUint& b) {
  BigUint quotation(0);
  BigUint remain = a;
  for (int shift = max(a.size() - b.size(), 0); shift >= 0; --shift) {
    const BigUint temp = BigUint(slow_division(remain >> shift, b));
    remain -= (temp * b) << shift;
    quotation += temp << shift;
  }
  return quotation;
}

BigUint operator>> (const BigUint& a, int n) {
  BigUint b = a;
  b.rs(n);
  return b;
}

BigUint operator<< (const BigUint& a, int n) {
  BigUint b = a;
  b.ls(n);
  return b;
}

ostream& operator<< (std::ostream& stream, const BigUint& b){
   return b.print(stream);
}