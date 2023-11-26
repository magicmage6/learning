#ifndef __BIG_UINT_H
#define __BIG_UINT_H

#include <iostream>
#include <string>

#include <vector>

using namespace std;

class BigUint {
public:
  BigUint(const int i = 0);

  BigUint(const string s);

  int size() const;

  ostream& print(ostream& out) const;

  int operator[](int i) const;

  void operator+=(const BigUint& b);

  void operator-=(const BigUint& b);

  void operator*=(int b);

  void operator*=(const BigUint& b);

  void operator/=(const BigUint& b);

  void rs(int n);

  void ls(int n);

private:
  vector<int> _data;
};

bool operator== (const BigUint& a, const BigUint& b);

bool operator> (const BigUint& a, const BigUint& b);

bool operator< (const BigUint& a, const BigUint& b);

BigUint operator+ (const BigUint& a, const BigUint& b);

BigUint operator- (const BigUint& a, const BigUint& b);

BigUint operator* (const BigUint& a, const BigUint& b);

BigUint operator/ (const BigUint& a, const BigUint& b);

BigUint operator% (const BigUint& a, const BigUint& b);

BigUint operator>> (const BigUint& a, int n);

BigUint operator<< (const BigUint& a, int n);

ostream& operator<< (std::ostream& stream, const BigUint& b);

#endif