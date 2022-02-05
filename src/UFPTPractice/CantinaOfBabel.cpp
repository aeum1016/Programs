#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>


int main(){

  std::map<std::string, std::vector<std::string>> speaks;
  std::map<std::string, std::vector<std::string>> understands;
  std::map<std::string, std::vector<std::string>> adj;

  int q = 0;
  std::cin >> q;

  std::string line;

  while(std::getline(std::cin, line, ' '))
  {
    std::string charName;
    charName = line.substr(0, line.find(' '));
    adj.emplace(charName);

    line = line.substr(line.find(' '));

    bool spoken = true;
    std::stringstream lineStream(line);
    std::string language;
    while(std::getline(lineStream, language, ' '))
    {
      if(spoken)
      {
        spoken = false;
        for(std::string character : understands[language])
        {
          adj[charName].push_back(character);
        }
      }
      for(std::string character : speaks[language])
      {
        adj[character].push_back(charName);
      }
    }
  }
  
  return 0;
}