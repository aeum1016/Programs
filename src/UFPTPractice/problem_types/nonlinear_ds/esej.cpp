#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b; cin >> a >> b;

  int words = max(a, (b/2)+1);


  for(int i = 0; i < words; i++)
  {
    string word = "";
    for(int j = 0; j < 15; j++)
    {
      word += (char)('a' + (rand()%26));
    }
    cout << word << " ";
  }
}