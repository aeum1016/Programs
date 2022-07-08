#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  vector<string> ones({"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"});
  vector<string> tens({"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"});
  vector<string> huns({"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"});
  // vector<string> thos({"", "M", "MM", "MMM", "MMMM"});
  vector<string> firstThousand;

  string thousand = "M";
  firstThousand.push_back(thousand);

  // for(string tho : thos)
  // {
    for(string hun : huns)
    {
      for(string ten : tens)
      {
        for(string one : ones)
        {
          if(hun+ten+one != "") firstThousand.push_back(hun + ten + one);
        }
      }
    }
  // }

  sort(firstThousand.begin(), firstThousand.end());

  int q; scanf("%d", &q);
  while(q--)
  {
    int num;
    scanf("%d", &num);
    int thousands = num/1000;
    num = num % 1000;
    string numS = (num == 0) ? "M" : huns[num/100] + tens[(num/10)%10] + ones[(num%10)];
    int location = find(firstThousand.begin(), firstThousand.end(), numS) - firstThousand.begin();
    if(location > 945)
    {
      cout << (location - 1000) + (thousands * -54) << endl;
    }
    else
    {
      cout << (location != 945 ? location + 1 : 0) + (thousands * 946) << endl;
    }
  }
}