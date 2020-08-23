#include <iostream>
#include <limits>
#include <math.h>

typedef std::numeric_limits< double > dbl;

using namespace std;

int main() {
  int i = 0;
  cout << "i is " << i << endl;
  i = i + 1;
  cout.precision(dbl::max_digits10);
  cout << "now i is " << i << endl;
  double a = 2.311111111111111111111111111;
  cout << "a is " << a << endl;
  float b = 3.51111111111111111111111111;
  cout << "b is " << b << endl;

  i = 5;
  int j = i / 2;
  cout << "j is " << j << endl;

  a = 5;
  double c = a / 2;
  cout << "c is " << c << endl;

   b = 5;
   float d = b / 2;
   cout << "d is " << d << endl;

   double answer;
   cout << "Please input your answer: ";
   cin >> answer;
   cout <<  "Your answer is " << answer << endl;

   if (answer >= 0) {
     float e = sqrt(answer);
     cout << "The sqrt of your answer is " << e << endl;
   } else {
     cout << "I can't calculate the sqrt of your answer because it is less than 0." << endl;
   }   
}
