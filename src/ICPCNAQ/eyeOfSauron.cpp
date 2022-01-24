#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string in;
    cin >> in;
    stack<char> stck;
    if(in.length() % 2 == 1 ){
      cout << "fix";
      return 0;
    }

    for(int i = 0; i < in.length()/2-1; i++)
    {
      stck.push(in[i]);
    }

    if(in[in.length()/2-1] != '(' || in[in.length()/2] != ')'){
      cout << "fix";
      return 0;
    }

    for(int i = in.length()/2+1; i < in.length(); i++)
    {
      if(in[i] == stck.top() || (in[i] == ')' && stck.top() == '('))
      {
        stck.pop();
      }
    }

    cout << (stck.empty() ? "correct" : "fix");

    return 0;
}