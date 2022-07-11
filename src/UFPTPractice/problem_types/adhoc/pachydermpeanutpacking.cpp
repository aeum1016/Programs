#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
  int nBoxes;
  while(scanf("%d\n", &nBoxes) != EOF)
  {
    if(nBoxes == 0) return 0;
    vector<vector<double>> boxes(nBoxes);
    int i = 0;
    while(nBoxes--)
    {
      double x1, y1, x2, y2;
      string size;
      cin >> x1 >> y1 >> x2 >> y2;
      cin >> size;
      boxes[i] = {x1, y1, x2, y2, (size == "small" ? 0.0 : size == "medium" ? 1.0 : 2.0)};
      i++;
    }
    int nNuts;
    cin >> nNuts;
    while(nNuts--)
    {
      double x1, y1;
      string size;
      cin >> x1 >> y1;
      cin >> size;
      bool boxed = false;
      for(vector<double> area : boxes)
      {
        if(x1 >= area[0] && y1 >= area[1] && x1 <= area[2] && y1 <= area[3])
        {
          if(size == "small" && area[4] == 0.0 || size == "medium" && area[4] == 1.0 || size == "large" && area[4] == 2.0)
          {
            cout << size << " " << "correct" << endl;
            boxed = true;
          }
          else
          {
            cout << size << " " << (area[4] == 0.0 ? "small" : area[4] == 1.0 ? "medium" : "large") << endl;
            boxed = true;
          }
        }
      }
      if(!boxed) cout << size << " " << "floor" << endl;
    }
    cout << endl;
  }
}