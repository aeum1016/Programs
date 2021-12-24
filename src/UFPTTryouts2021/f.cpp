#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    long ans = 0;
    long add = 1;
    while(n > 0)
    {
        ans += add;
        if(n % 10 == 7)
        {
            ans += add;
        }
        
        n /= 10;
        add *= 2;
    }

    cout << ans << endl;

    return 0;
}