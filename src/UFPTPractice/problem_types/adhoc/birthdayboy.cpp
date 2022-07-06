#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  vector<bool> birthdays(365, false);
  vector<int> daysInMonth({0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365});
  int q; scanf("%d", &q);
  while(q--)
  {
    string name;
    int month, day;
    char c;
    cin >> name >> month >> c >> day;
    int date = daysInMonth[month-1] + (day-1);
    birthdays[date] = true;
  }

  int gap = 0;
  int maxGap = 0;
  int endGap = 299;

  for(int i = 0; i <= 710; i++)
  {
    int date = i%365;
    if(birthdays[date])
    {
      if(gap >= maxGap)
      {
        if(gap > maxGap || (date+64)%365 < (endGap+65)%365)
        {
          maxGap = gap;
          endGap = (date+364) % 365;
        }
      }
      gap = 0;
    }
    else
    {
      gap++;
    }
  }


  int month, day;
  for(int i = 0; i < 12; i++)
  {
    if(endGap >= daysInMonth[i])
    {
      month = i+1;
      day = endGap - daysInMonth[i]+1;
    }
  }
  cout << setfill('0') << setw(2) << month << "-" << setw(2) << day;
}