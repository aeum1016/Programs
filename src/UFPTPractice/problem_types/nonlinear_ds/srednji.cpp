#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, b; cin >> n >> b;
  int index = -1;
  int i = 0;
  vector<int> nums;

  while(i < n)
  {
    int a; cin >> a;
    if(a == b) index = i;
    nums.push_back(a);
    i++;
  }

  map<int, int> m;
  m[0] = 1;
  int sum = 0;
  for(int i = index+1; i < n; i++)
  {
    if(nums[i] > b) sum++;
    else sum--;
    m[sum]++;
  }

  long long ans = m[0];
  sum = 0;
  for(int i = index-1; i >= 0; i--)
  {
    if(nums[i] > b) sum++;
    else sum--;
    ans += m[-sum];
  }

  cout << ans;

}