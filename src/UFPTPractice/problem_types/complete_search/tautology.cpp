#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  stack<bool> operands;
  bool n1, n2;
  char c;
  int i;
  bool taut;
  while(getline(cin, s)) {
    if(s == "0") return 0;

    taut = true;
    
    for(i = 0; i < 32; i++) {
      for(int j = s.size()-1; j >= 0; j--) {
        c = s.at(j);
        if(c >= 'a') {
          if(c == 'p') operands.push(i & 16);
          else if(c == 'q') operands.push(i & 8);
          else if(c == 'r') operands.push(i & 4);
          else if(c == 's') operands.push(i & 2);
          else if(c == 't') operands.push(i & 1);
        }
        else {
          if(c == 'N') {
            n1 = !operands.top();
            operands.pop();
            operands.push(n1);
          }
          else if(c == 'K') {
            n1 = operands.top();
            operands.pop();
            n2 = operands.top();
            operands.pop();
            operands.push(n1 & n2);
          }
          else if(c == 'A') {
            n1 = operands.top();
            operands.pop();
            n2 = operands.top();
            operands.pop();
            operands.push(n1 | n2);
          }
          else if(c == 'C') {
            n1 = operands.top();
            operands.pop();
            n2 = operands.top();
            operands.pop();
            operands.push(!(n1 == 1 && n2 == 0));
          }
          else if(c == 'E') {
            n1 = operands.top();
            operands.pop();
            n2 = operands.top();
            operands.pop();
            operands.push(n1 == n2);
          }
        }
      }

      bool ans = operands.top(); operands.pop();
      if(!ans) {
        taut = false;
        break;
      }
    }
    if(taut) cout << "tautology\n";
    else cout << "not\n";
  }
  return 0; 
}