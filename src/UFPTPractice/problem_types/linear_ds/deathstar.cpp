#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int size; cin >> size;

  vector<int> code(size, 0);

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      int a; cin >> a;
      code[i] |= a;
    }
  }
  for(int i : code)
  {
    cout << i << " ";
  }
}