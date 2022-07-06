#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

bool properDate(int year, int month, int day)
{
  if(month > 12) return false;
  vector<int> daysInMonth({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
  if(!(year % 4) && (year % 100 || !(year % 400)))
  {
    daysInMonth[1] = 29;
  }
  if(day > daysInMonth[month-1]) return false;
  return true;
}

int main()
{
  string date;
  getline(cin, date);
  stringstream dateS(date);
  char c;
  int one, two, three;
  dateS >> one >> c >> two >> c >> three;
  vector<int> nums;
  nums.push_back(one);  
  nums.push_back(two);  
  nums.push_back(three);

  int year, month, day;
  int lowYear = 0, lowMonth = 0, lowDay = 0;
  
  for(int i = 0; i < 3; i++)
  {
    for(int j = 1; j <= 2; j++)
    {
      if(properDate(nums[i], nums[(i+j) % 3], nums[(i+3-j) % 3]))
      {
        if(nums[i] < lowYear || nums[i] == lowYear && nums[(i+j) % 3] < lowMonth || nums[i] == lowYear && nums[(i+j) % 3] == lowMonth && nums[(i+3-j) % 3] < lowDay || !lowDay)
        {
          lowYear = nums[i];
          lowMonth = nums[(i+j) % 3];
          lowDay = nums[(i+3-j) % 3];
        }
      }
    }
  }
  if(lowDay)
  {
    string yearS = to_string(lowYear);
    if(yearS.size() == 2)
    {
      yearS = "20" + yearS;
    }
    else if(yearS.size() == 1)
    {
      yearS = "200" + yearS;
    }
    cout << yearS << '-' << setfill('0') << setw(2) << lowMonth << '-' << setw(2) << lowDay << endl;
  }
  else{
    cout << date << " is illegal";
  }
  return 0;
}