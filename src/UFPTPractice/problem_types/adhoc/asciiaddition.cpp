#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  vector<string> nums;
  nums.push_back("xxxxxx...xx...xx...xx...xx...xxxxxx");
  nums.push_back("....x....x....x....x....x....x....x");
  nums.push_back("xxxxx....x....xxxxxxx....x....xxxxx");
  nums.push_back("xxxxx....x....xxxxxx....x....xxxxxx");
  nums.push_back("x...xx...xx...xxxxxx....x....x....x");
  nums.push_back("xxxxxx....x....xxxxx....x....xxxxxx");
  nums.push_back("xxxxxx....x....xxxxxx...xx...xxxxxx");
  nums.push_back("xxxxx....x....x....x....x....x....x");
  nums.push_back("xxxxxx...xx...xxxxxxx...xx...xxxxxx");
  nums.push_back("xxxxxx...xx...xxxxxx....x....xxxxxx");
  nums.push_back(".......x....x..xxxxx..x....x.......");

  string line;
  vector<string> a;
  while(getline(cin, line))
  {
    for(int i = 0; i < (line.size()+1)/6; i++)
    {
      string num = line.substr(i*6, 5);
      if(a.size() == i)
      {
        a.push_back(num);
      }
      else
      {
        a.at(i) += num;
      }
    }
  }

  int first = 0, second = 0;
  bool firstN = true;
  for(int i = 0; i < a.size(); i++)
  {
    int num = find(nums.begin(), nums.end(), a.at(i)) - nums.begin();
    if(num != 10)
    {
      if(firstN)
      {
        first*=10;
        first+=num;
      }
      else
      {
        second*=10;
        second+=num;
      }
    }
    else firstN = false;
  }

  string ans = to_string(first+second);

  for(int i = 0; i < 7; i++)
  {
    for(int j = 0; j < ans.size(); j++)
    {
      char c = ans.at(j);
      cout << nums.at(c-'0').substr(i*5, 5);
      if(j != ans.size()-1) cout << ".";
    }
    cout << endl;
  }
  
}
