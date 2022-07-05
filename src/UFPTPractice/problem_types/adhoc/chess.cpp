#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

vector<int> steps(int X1, int Y1, int X2, int Y2, bool iM, bool jM, vector<int> step1, vector<int> step2){
  for(int i = X1, j = Y1; i <= 8 && i >= 1 && j <= 8 && j >= 1; iM ? i++ : i--, jM ? j++ : j--)
  {
    int k = i;
    int l = j;
    for(int m = 0; m < 2; m++)
    {
      k+=step1[m];
      l+=step2[m];
      while(k <= 8 && k >= 1 && l <= 8 && l >= 1)
      {
        if(k==X2 && l==Y2)
        {
          return vector<int>({i, j});
        }
        k+=step1[m];
        l+=step2[m];
      }
    }
  }
  return vector<int>({});
}

void chess(char x1, char y1, char x2, char y2)
{
    bool white1 = ((int) (x1-'A'+1) + (int)(y1-'1'+1)) % 2;
    bool white2 = ((int) (x2-'A'+1) + (int)(y2-'1'+1)) % 2;
    if(white1 != white2)
    {
      printf("Impossible\n");
      return;
    }
    else if(x1 == x2 && y1 == y2)
    {
      printf("0 %c %c\n", x1, y1);
      return;
    }
    int X1 = x1-'A'+1, Y1 = y1-'1'+1, X2 = x2-'A'+1, Y2 = y2-'1'+1;
    int X3 = 0, Y3 = 0;

    vector<int> XY3({0, 0});
    vector<int> temp;

    temp = steps(X1, Y1, X2, Y2, true, true, {1, -1}, {-1, 1});
    if(!temp.empty()) XY3 = temp;
    temp = steps(X1, Y1, X2, Y2, false, false, {1, -1}, {-1, 1});
    if(!temp.empty()) XY3 = temp;
    temp = steps(X1, Y1, X2, Y2, true, false, {1, -1}, {1, -1});
    if(!temp.empty()) XY3 = temp;
    temp = steps(X1, Y1, X2, Y2, false, true, {1, -1}, {1, -1});
    if(!temp.empty()) XY3 = temp;
    X3 = XY3[0];
    Y3 = XY3[1];

    if(X3 == X1 || X3 == X2)
    {
      printf("1 %c %c %c %c\n", x1, y1, x2, y2);
    }
    else
    {
      printf("2 %c %c %c %c %c %c\n", x1, y1, X3+'A'-1, Y3+'1'-1, x2, y2);
    }
}

int main()
{

  int q; scanf("%d\n", &q);
  while(q--)
  {
    char x1, y1, x2, y2; scanf("%c %c %c %c\n", &x1, &y1, &x2, &y2);
    // for(int a = 0; a < 8; a++)
    // {
    //   for(int b = 0; b < 8; b++)
    //   {
    //     for(int c = 0; c < 8; c++)
    //     {
    //       for(int d = 0; d < 8; d++)
    //       {
    //         char A = a+'A';
    //         char B = b+'1';
    //         char C = c+'A';
    //         char D = d+'1';
    //         printf("%c %c %c %c\n", A, B, C, D);
    //         chess(A, B, C, D);
    //       }
    //     }
    //   }
    // }
    chess(x1, y1, x2, y2);
  }
}