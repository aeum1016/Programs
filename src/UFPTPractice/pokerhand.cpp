#include <stdio.h>
#include <cmath>
#include <unordered_map>

int main()
{
  std::unordered_map<char, int> counts;
  int max = 1;
  for(int i = 0; i < 5; i++)
  {
    char card[3];
    scanf("%s", card);
    if(counts.find(*card) == counts.end())
    {
      counts.emplace(*card, 1);
    }
    else{
      counts[*card] = counts.at(*card) + 1;
      if(counts.at(*card) > max) max = counts.at(*card);
    }
  }
  printf("%d", max);
  return 0;
}

// emplace does not update :)