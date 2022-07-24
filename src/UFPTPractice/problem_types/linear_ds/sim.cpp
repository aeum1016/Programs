#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc; scanf("%d\n", &tc);

    while(tc--)
    {
      string line;
      getline(cin, line);
      list<char> listA;
      auto ptr = listA.begin();
      int i = 0;
      for(char c : line)
      {
        if(c == ']')
        {
          ptr = listA.end();
        }
        else if(c == '[') ptr = listA.begin();
        else if(c == '<')
        {
          if(ptr != listA.begin())
          {
            auto ptr2 = ptr;
            ptr2--;
            listA.erase(ptr2);
          }
        }
        else
        {
          listA.insert(ptr, c);
        }
      }
      for(char c : listA)
      {
        cout << c;
      }
      cout << endl;
    }

    return 0;
}