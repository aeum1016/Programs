#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n; cin >> n;
  for(int i = 1; i < sqrt(n); i++)
  {
    if(!(n % i)) cout << i-1 << " ";
  }
  for(int i = sqrt(n); i >= 1; i--)
  {
    if(!(n % i)) cout << (n/i)-1 << " ";
  }
}