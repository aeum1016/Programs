#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

int main()
{
  string input = "";
  cin >> input;

  vector<int> stk;


  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] == '1') stk.push_back(1);
    else if(input[i] == '+'){
      int input1 = stk[stk.size()-1];
      stk.pop_back();
      int input2 = stk[stk.size()-1];
      stk.pop_back();
      for(auto j = stk.begin(); j != stk.end(); j++)
      {
        *j -= 1;
      }

      stk.push_back(input1+input2);
    }
  }

  for(auto j = stk.begin(); j != stk.end(); j++)
  {
    cout << *j;
  }

  
  
  return 0;
}