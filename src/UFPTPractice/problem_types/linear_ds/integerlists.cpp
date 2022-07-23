#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while(q--)
    {
      string s; cin >> s;
      int n; cin >> n;
      string nums; cin >> nums;
      nums = nums.substr(1, nums.size()-2);
      bool reverse = false;
      bool error = false;
      
      stringstream ss(nums);
      string num;
      deque<int> d;
      while(getline(ss, num, ','))
      {
        d.push_back(stoi(num));
      }

      for(char c : s)
      {
        if(c == 'R') reverse = !reverse;
        else
        {
          if(d.empty())
          {
            error = true;
            break;
          }
          if(reverse) d.pop_back();
          else d.pop_front();
        }
      }
      if(!error)
      {
        if(!reverse)
        {
          cout << "[";
          for(auto it = d.begin(); it != d.end(); it++)
          {
            cout << *it;
            if(it != d.end()-1) cout << ",";
          }
          cout << "]";
        }
        else
        {
          cout << "[";
          for(auto it = d.rbegin(); it != d.rend(); it++)
          {
            cout << *it;
            if(it != d.rend()-1) cout << ",";
          }
          cout << "]";
        }
        cout << endl;
      }
      else cout << "error\n";
    }
  return 0;
}