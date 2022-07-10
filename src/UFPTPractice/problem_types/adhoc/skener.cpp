#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int r, c;
  int h, w;
  scanf("%d %d %d %d\n", &r, &c, &h, &w);
  
  vector<vector<char>> en(r*h, vector<char>(c*w));

  for(int i = 0; i < r; i++)
  {
    char ch;
    for(int j = 0; j < c; j++)
    {
      scanf("%c", &ch);
      for(int k = 0; k < h; k++)
      {
        for(int l = 0; l < w; l++)
        {
          en.at((i*h)+k)[(j*w)+l] = ch;
        }
      }
    }
    scanf("%c", &ch);
  }

  for(vector<char> a : en)
  {
    for(char b : a)
    {
      printf("%c", b);
    }
    printf("\n");
  }

  return 0;
}