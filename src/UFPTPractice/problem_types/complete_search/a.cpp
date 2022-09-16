#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(int a) {
  string s = to_string(a);

  for(int i = 0; i < s.length()/2; i++) {
    if(s[i] != s[s.length()-i-1]) return false;
  }
  return true;
}

int main() {

  int ans = 0;

  for(int i = 100000; i < 1000000; i++) {
    if(isPalindrome(i)) ans++;
  }
  cout << ans;
}