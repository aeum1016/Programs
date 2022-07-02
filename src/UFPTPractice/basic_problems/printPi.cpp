#define _USE_MATH_DEFINES

#include <string>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double pi = M_PI;
  int digits;
  scanf("%i", &digits);
  cout << setprecision(digits+1);
  long long piInt = pi * pow(10, digits);
  cout << piInt / pow(10, digits);

  return 0;
};