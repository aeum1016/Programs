#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
  int l = 0, e = 0;
  cin >> l >> e;

  vector<bool> lines(l+1, false);

  for(int i = 0; i < e; i++)
  {
    int q = 0;
    cin >> q;
    lines[q-1] = true;
  }

  vector<string> errorsList;
  string errors = "";
  int previousNum = 0;
  bool previous = false;

  for(int i = 0; i <= l; i++){
    if(lines[i]){
      if(previous)
      {
        //do nothing
      }
      else{
        errors += to_string(i+1);
        previousNum = i+1;
        previous = true;
      }
    }
    else{
      if(previous)
      {
        if(previousNum != i)
        {
          errors += "-";
          errors += to_string(i);
          errorsList.push_back(errors);
          errors = "";
          previous = false;
        }
        else
        {
          errorsList.push_back(errors);
          previous = false;
          errors = "";
        }
      }
    }
  }

  string good = "";
  previous = false;
  vector<string> goodList;
  previousNum = 0;
  lines[lines.size()-1] = true;

  for(int i = 0; i <= l; i++){
    if(!lines[i]){
      if(previous)
      {
        //do nothing
      }
      else{
        good += to_string(i+1);
        previousNum = i+1;
        previous = true;
      }
    }
    else{
      if(previous)
      {
        if(previousNum != i)
        {
          good += "-";
          good += to_string(i);
          goodList.push_back(good);
          previous = false;
          good = "";
        }
        else
        {
          goodList.push_back(good);
          good = "";
          previous = false;
        }
      }
    }
  }

  std::cout << "Errors: ";
  if(errorsList.size() > 1)
  {
    for(int i = 0; i < errorsList.size()-2; i++)
    {
      std::cout << errorsList.at(i) << ", ";
    }
    std::cout << errorsList.at(errorsList.size()-2) << " ";
    std::cout << "and " << errorsList.at(errorsList.size()-1);
  }
  else std::cout << errorsList.at(goodList.size()-1);

  std::cout << endl << "Correct: ";
  if(goodList.size() > 1){
    for(int i = 0; i < goodList.size()-2; i++)
    {
      std::cout << goodList.at(i) << ", ";
    }
    std::cout << goodList.at(goodList.size()-2) << " ";
    std::cout << "and " << goodList.at(goodList.size()-1);
  }
  else std::cout << goodList.at(goodList.size()-1);

    return 0;
}