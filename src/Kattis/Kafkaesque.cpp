#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int c = 0;
    cin >> c;
    int count = 1;
    int last = 0;
    cin >> last;
    for(int i = 1; i < c; i++){
      int comparison = 0;
      cin >> comparison;
      if (comparison < last)
        count++;
      last = comparison;
    }
    cout << count;

    return 0;
}