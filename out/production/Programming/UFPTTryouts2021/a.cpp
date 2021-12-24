#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = 0;
    unsigned int h = 0;
    unsigned int v = 0; 

    cin >> n >> h >> v;

    h = max(h, n-h);
    v = max(v, n-v);

    cout << h*v*4;

    return 0;
}