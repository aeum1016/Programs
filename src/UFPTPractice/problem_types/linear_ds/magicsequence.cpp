#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int* counting_sort(int* S, int size, int place)
{
  int freq[10000];
  fill(freq, freq+10000, 0);
  int* R = new int[size];
  fill(R, R+size, 0);
  int digit = (int)pow(10000, place);
  for(int i = 0; i < size; i++)
  {
    freq[(S[i]/digit) % 10000]++;
  }
  for(int i = 1; i < 10000; i++)
  {
    freq[i] = freq[i] + freq[i-1];
  }
  for(int i = size-1; i >= 0; i--)
  {
    R[--freq[(S[i]/digit) % 10000]] = S[i];
  }
  return R;
}

int* radix_sort(int* S, int size, int digits)
{
  for(int i = 0; i < digits; i++)
  {
    S = counting_sort(S, size, i);
  }
  return S;
}

int main()
{
  int tc; scanf("%d", &tc);
  while(tc--)
  {
    int n; scanf("%d", &n);
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    int x, y; scanf("%d %d", &x, &y);
    int* S = new int[n];
    S[0] = a;
    int digits = a;

    for(int i = 1; i < n; i++)
    {
      S[i] =  (((long long)S[i-1]) * b + a) % c;
      digits = fmax(S[i], digits);
    }
    
    // digits = digits >= 31623 ? 2 : 1;
    digits = (to_string(digits).size() + 3) / 4;
    S = radix_sort(S, n, digits);

    long long v = 0;
    for(int i = 0; i < n; i++)
    {
      v = (v * x + S[i]) % y;
    }

    cout << v << endl;
  }
}