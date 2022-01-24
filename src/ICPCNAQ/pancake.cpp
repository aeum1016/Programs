#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
#include <tgmath.h>

using namespace std;

int num_additions(string q)
{
  int ans = 0;
  for(int i = 0; i < q.length(); i++)
  {
    if(q[i] == '+') ans++;
  }
  return ans;
}

string two_power_string(int q)
{
  if(q == 0) return "";
  if(q == 1) return "1+";
  string ans = "11+";
  q /= 2;
  
  while(q > 1)
  {
    ans += "d+";
    q /= 2;
  }
  return ans;
}

string string_result(int q)
{
  string res = "";
  string ans = "";
  int total = 0;
  int count = 0;
  for(int k = 0; k < 24; k++)
  {
    int j = 1;
    if(((j << k) & q) != 0){
      cout << k << " " << q << endl;
      res = two_power_string(pow(2, k)) + string_result(num_additions(string_result(total)));
      total += pow(2, k);
      ans = res + ans;
    }
  }

  
    
  return ans;

}

int main()
{

  int q = 0;
  cin >> q;

  stack<int> nums;
  vector<long long> adds;

  for(int i = 0; i < q; i++)
  {
    int n;
    cin >> n;
    nums.push(n);
  }

  for(int i = 0; i < q; i++)
  {
    cout << string_result(nums.top()) << endl;
  }

  return 0;
}