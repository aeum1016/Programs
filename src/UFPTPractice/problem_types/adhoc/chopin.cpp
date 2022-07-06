#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
  unordered_map<string, string> twoTone;
  twoTone.emplace("Ab", "G#");
  twoTone.emplace("G#", "Ab");
  twoTone.emplace("A#", "Bb");
  twoTone.emplace("Bb", "A#");
  twoTone.emplace("C#", "Db");
  twoTone.emplace("Db", "C#");
  twoTone.emplace("D#", "Eb");
  twoTone.emplace("Eb", "D#");
  twoTone.emplace("F#", "Gb");
  twoTone.emplace("Gb", "F#");

  string line;
  int caseN = 1;
  while(getline(cin, line))
  {
    printf("Case %d: ", caseN);
    string key = line.substr(0, 2);
    string tonality = line.substr(3);
    if(twoTone.find(key) != twoTone.end())
    {
      key = twoTone.at(key);
      cout << key << " " << tonality << endl;
    }
    else cout << "UNIQUE\n";
    caseN++;
  }
}