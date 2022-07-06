#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int q; scanf("%d", &q);
  while(q--)
  {
    int f13 = 0;
    int d, m; scanf("%d %d", &d, &m);
    vector<int> dayInMonth(m);
    for(int i = 0; i < m; i++)
    {
      int days; scanf("%d", &days);
      dayInMonth[i] = days;
    }

    int day = 0;
    int month = 0;
    int dayOfMonth = 1;

    for(int i = 0; i < d; i++)
    {
      if(day == 5 && dayOfMonth == 13) f13++;
      
      day = (day+1)%7;
      if(dayOfMonth == dayInMonth[month])
      {
        dayOfMonth = 1;
        month++;
      }
      else
      {
        dayOfMonth++;
      }
    }
    printf("%d\n", f13);
  }
  return 0;
}