#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

int getHashValue(std::string m, int power, int modulo){
  long long hashValue = 0;
  for(int i = 0; i < m.length(); i++)
  {
    hashValue += (m[i]-96) * std::pow(power,i);
  }
  int intHash = hashValue % modulo;
  return intHash;
}

int main(){



  
  
  return 0;
}