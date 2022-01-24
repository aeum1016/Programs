#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

int main(){

  std::vector<std::vector<std::string>> dups;
    dups.push_back({"yes", "yes"});
    dups.push_back({"no", "no"});
    dups.push_back({"maybe", "yes"});
    dups.push_back({"yes", "yes"});
    dups.push_back({"maybe", "yes"});
    dups.push_back({"yes", "yes"});
    dups.push_back({"believe so", "yes"});
    dups.push_back({"haiya", "yes"});
    dups.push_back({"believe so", "yes"});
    dups.push_back({"hello", "yes"});
  std::vector<std::vector<std::string>> noDups;

  std::unordered_set<std::string> added;

  for(int i = 0; i < dups.size(); i++)
  {
    if(added.find(dups[i][0]) != added.end()){
      //do nothing
    }
    else{
      added.emplace(dups[i][0]);
      noDups.push_back(dups[i]);
    }
  }

  for(int i = 0; i < noDups.size(); i++)
  {
    std::cout << noDups[i][0] << " " << noDups[i][1] << std::endl;
  }

  return 0;
}