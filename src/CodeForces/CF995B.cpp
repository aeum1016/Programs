#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> firstPos;
    map<int, int> closed;
    map<int, int> open;
    int jumps = 0;
    int closedPairs = 0;

    for(int i = 0; i < 2*n; i++)
    {
        int newVal;
        cin >> newVal;
        if(firstPos.find(newVal) == firstPos.end())
        {
            firstPos.emplace(newVal, i);
            closed.emplace(newVal, closedPairs);
            open.emplace(newVal, open.size());
        }
        else
        {
            jumps += (i - firstPos.find(newVal)->second - 1) - (closedPairs - closed.find(newVal)->second);
            closedPairs++;
        }
    }
    cout << jumps << endl;
}