#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  cin >> s;
  if(s.size() % 2) {
    cout << "fix";
    return 0;
  }
  if(s.at(((s.size())/2)-1) == '(' && s.at(s.size()/2) == ')') cout << "correct";
  else cout << "fix"; 

  return 0;
}