#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int q = 0;
    cin >> q;

    int j = 0;
    int base = 0;

    for(int i = 0; i < q; i++)
    {
      if(base == 0){
        cin >> base;
      }
      else{
        cin >> j;
        
        if(j % base == 0){
          cout << j << endl;
          base = 0;
        }

      }
    } 
    return 0;
}