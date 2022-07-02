#include <iostream>
#include <string>
#include <vector>
#include <map>

bool checkBipartite(std::vector<std::vector<int>>& interactions, std::vector<int>& genders, int gender, int vertice)
  {
    genders[vertice] = gender;
    for(int vertices : interactions[vertice])
    {
      if(genders[vertices] == -1)
      {
        if(!checkBipartite(interactions, genders, 1-gender, vertices))
          return false;
      }
      else if(genders[vertice] == genders[vertices])
        return false;
    }
    return true;
  }

int main(){

  int q = 0;
  std::cin >> q;

  for(int k = 0; k < q; k++)
  {
    int b = 0, i = 0;
    std::cin >> b >> i;

    std::vector<std::vector<int>> interactions(b);
    std::vector<int> genders(b, -1); 

    for(int j = 0; j < i; j++)
    {
      int x, y;
      std::cin >> x >> y;
      interactions[x-1].push_back(y-1);
      interactions[y-1].push_back(x-1);
    }

    bool isBipartite = true;
    for(int j = 0; j < b; j++)
    {
      if(genders[j] == -1)
      {
        if(!checkBipartite(interactions, genders, 0, j)) 
        {
          isBipartite = false;
          break;
        }
      }
    }
    std::string output = isBipartite ? "No suspicious bugs found!" : "Suspicious bugs found!";

    std::cout << "Scenario #" << (k+1) << ":\n";
    std::cout << output << "\n";
  }
  
  return 0;
}