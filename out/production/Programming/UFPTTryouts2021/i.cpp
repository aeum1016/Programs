#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int t;
    cin >> t;

    while(t--)
    {
        unsigned int cols;
        cin >> cols;

        vector<int> totPoints;
        vector<int> totPoints2;
        totPoints2.push_back(0);

        long points;
        for(unsigned int i = 0; i < cols; i++)
        {
            int newPoints;
            cin >> newPoints;
            points += newPoints;
            totPoints.push_back(points);
        }
        points = 0;
        for(unsigned int i = 0; i < cols; i++)
        {
            int newPoints;
            cin >> newPoints;
            points += newPoints;
            totPoints2.push_back(points);
        }

        int ans = INT_MAX;

        for(unsigned int i = 0; i < cols; i++)
        {
            ans = min(ans, max(totPoints.at(cols-1) - totPoints.at(i), totPoints2.at(i)));
        }
        cout << ans << endl;
    }

    return 0;
}