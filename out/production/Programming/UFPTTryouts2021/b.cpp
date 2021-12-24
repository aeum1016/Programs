#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = 0; 

    cin >> n;

    while(n--)
    {
        int val = 0;
        cin >> val;
        int m = 1;
        while(val % (m*10) == 0)
        {
            m*=10;
        }
        val -= m;
        cout << val << endl;
    }

    return 0;
}