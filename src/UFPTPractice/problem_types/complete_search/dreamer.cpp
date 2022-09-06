#include <bits/stdc++.h>

using namespace std;

int eDay, eMonth, eYear;

int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char date[8];

int possibleDates;

bool validDate(int d, int m, int y) {
  if(y < 2000 || d > daysInMonth[m-1] || d < 1 || m > 12 || m < 1) return false;
  bool leapyear = (y % 400 == 0) || ((y % 4 == 0) && !(y % 100 == 0));
  if(m == 2 && d == 29 && !leapyear) return false;

  if(y < eYear || (y == eYear && m < eMonth) || (y == eYear && m == eMonth && d < eDay)) {
    eDay = d;
    eMonth = m;
    eYear = y;
  }
  return true;
}

int main() {

  int q; cin >> q;

  while(q--) {
    for(int i = 0; i < 8; i++) {cin >> date[i];}
    possibleDates = 0;
    eDay = 32, eMonth = 13, eYear = INT_MAX;

    sort(date, date+8);
    
    do {
      int day = (date[0]-'0')*10 + (date[1]-'0');
      int month = (date[2]-'0')*10 + (date[3]-'0');
      int year = (date[4]-'0')*1000 + (date[5]-'0')*100 + (date[6]-'0')*10 + (date[7]-'0');

      if(validDate(day, month, year)) {
        possibleDates++;
      }
    }
    while(next_permutation(date, date+8));

    if(possibleDates) cout << possibleDates << ' ' << setfill('0') << setw(2) << eDay << ' ' << setw(2) << eMonth << ' ' << eYear << "\n";
    else cout << "0\n";
  }

}