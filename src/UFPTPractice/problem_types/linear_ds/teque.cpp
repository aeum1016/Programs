#include <bits/stdc++.h>
using namespace std;

void fix(deque<int>& front, deque<int>& back)
{
  if((int)(front.size() - back.size()) >= 2)
  {
    back.push_front(front.back());
    front.pop_back();
  }
  else if((int)(back.size() - front.size()) >= 1)
  {
    front.push_back(back.front());
    back.pop_front();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  deque<int> front;
  deque<int> back;

  while(q--)
  {
    string s; cin >> s;
    int a; cin >> a;

    if(s == "push_back")
    {
      back.push_back(a);
      fix(front, back);
    }
    else if(s == "push_front")
    {
      front.push_front(a);
      fix(front, back);
    }
    else if(s == "push_middle")
    {
      front.push_back(a);
      fix(front, back);
    }
    else if(s == "get")
    {
      if(a >= front.size())
      {
        cout << back.at(a-front.size()) << endl;
      }
      else
      {
        cout << front.at(a) << endl;
      }
    }
    // cout << "front ";
    // for(auto it = front.begin(); it != front.end(); it++)
    // {
    //   cout << *it << " ";
    // }
    // cout << endl;    
    // cout << "back ";
    // for(auto it = back.begin(); it != back.end(); it++)
    // {
    //   cout << *it << " ";
    // }
    // cout << endl;
  }
  return 0;
}
