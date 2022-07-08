#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
  string line;
  while(getline(cin, line))
  {
    stringstream liness(line);
    string a;
    string name;
    int records = 0;
    double sum = 0.0;
    while(getline(liness, a, ' '))
    {
      if(a.at(0) >= 'a' && a.at(0) <= 'z' || a.at(0) >= 'A' && a.at(0) <= 'Z')
      {
        if(name.size())
        {
          name.append(" " + a);
        }
        else
        {
          name.append(a);
        }
      }
      else
      {
        records++;
        sum += stod(a);
      }
    }
    cout << setprecision(12) << sum/records << " " << name << endl;
  }
  return 0;
}