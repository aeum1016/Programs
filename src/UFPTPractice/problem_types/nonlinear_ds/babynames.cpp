#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>                         // pbds

using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ost female;
  ost male;

  int choice; cin >> choice;
  string name;
  string i1, i2;
  int gender;
  int ans;
  while(choice)
  {
    switch(choice)
    {
      case 1:
      {
        cin >> name >> gender;
        gender == 1 ? male.insert(name) : female.insert(name);
        break;
      }
    
      case 2:
      {
        cin >> name;
        auto it = male.lower_bound(name);
        if(*it == name) male.erase(male.lower_bound(name));
        else female.erase(female.lower_bound(name));
        break;
      }
    
     case 3:
     {
      cin >> i1 >> i2 >> gender;
      switch(gender)
      {
        case 0:
        {
          ans = male.order_of_key(i2) - male.order_of_key(i1) + female.order_of_key(i2) - female.order_of_key(i1);
          break;
        }
        case 1:
        {
          ans = male.order_of_key(i2) - male.order_of_key(i1);
          break;
        }
        case 2:
        {
          ans = female.order_of_key(i2) - female.order_of_key(i1);
          break;
        }
      }
      cout << ans << "\n";
     }
    }
    cin >> choice;
  }
  return 0;
}
