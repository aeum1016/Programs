#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  string line;
  vector<char> vowels({'a','e','i','o','u','y'});
  while(getline(cin, line))
  {
    stringstream words(line);
    string word;
    while(getline(words, word, ' '))
    {
      string newWord;
      if(find(vowels.begin(), vowels.end(), word.at(0)) != vowels.end())
      {
        newWord = word.append("yay");
      }
      else
      {
        int firstVow = word.size();
        for(char c : vowels)
        {
          firstVow = fmin(word.find(c), firstVow);
        }
        newWord = word.substr(firstVow).append(word.substr(0, firstVow)).append("ay");
      }
      cout << newWord << " ";
    }
    cout << endl;
  }
  return 0;
}