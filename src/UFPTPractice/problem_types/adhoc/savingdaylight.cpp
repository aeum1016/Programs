#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  string date;
  while(getline(cin, date))
  {
    stringstream dateStream(date);
    string m, d, y;
    char temp;
    dateStream >> m >> d >> y;
    int upHour, downHour, upMinute, downMinute;
    dateStream >> upHour >> temp >> upMinute >> downHour >> temp >> downMinute;

    int minutesUp = (downHour - upHour)*60 + (downMinute-upMinute); 
    cout << m << ' ' << d << ' ' << y << ' ';
    cout << minutesUp/60 << " hours ";
    cout << minutesUp%60 << " minutes" << endl;
  }
  return 0;
}