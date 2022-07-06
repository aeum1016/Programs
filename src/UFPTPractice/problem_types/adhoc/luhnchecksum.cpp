#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);
  while(q--)
  {
    string number; cin >> number;
    int sum = 0;
    for(int i = 0; i < number.size(); i++)
    {
      if(i%2 == number.size()%2)
      {
        string newNum = to_string(stoi(number.substr(i,1))*2);
        if(newNum.size() > 1)
        {
          newNum = to_string(stoi(newNum.substr(0,1)) + stoi(newNum.substr(1,1)));
        }
        sum += stoi(newNum);
      }
      else
      {
        sum += stoi(number.substr(i,1));
      }
    }
    printf("%s\n", sum%10 ? "FAIL" : "PASS");
  }
  return 0;
}