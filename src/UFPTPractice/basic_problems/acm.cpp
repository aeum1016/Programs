/**
 * @file acm.cpp
 * @author Alex Eum (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Lesson: Define size for char* and other arrays based on the problem
 * description. Messes up memory otherwise.
 * 
 */

#include <stdio.h>
#include <vector>
#include <cstring>

int main()
{
  int a = 0;
  int b = 0;
  int time = 0;
  char problem;
  char correct[6];
  char right[] = "right";
  std::vector<bool> corrects(26, 0);
  std::vector<int> times(26, 0);

  while(scanf("%d %c %s", &time, &problem, correct) != -1)
  {
    if(time == -1) break;
    else{
      if(!corrects[problem-'A'])
      {
        if(!strcmp(correct, right))
        {
          corrects[problem - 'A'] = true;
          b += times[problem-'A'] + time;
          a++;

        }
        else
        {
          times[problem-'A'] += 20;
        }
      }
    }
  }

  printf("%d %d", a, b);
  
  return 0;
}