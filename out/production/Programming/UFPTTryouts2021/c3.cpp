#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int n = 0; 

    cin >> n;

    while(n--)
    {
        map<long, int> pairs;
        vector<long> minimums;
        int caves;
        cin >> caves;
        while(caves--)
        {
            int monsters;
            cin >> monsters;
            long caveMin = 0;
            for(int i = 0; i < monsters; i++)
            {
                long monsterDefense;
                cin >> monsterDefense;
                caveMin = max(caveMin, monsterDefense - i + 1);
            }
            pairs.emplace(caveMin, monsters);
            minimums.push_back(caveMin);
        }
        
        sort(minimums.begin(), minimums.end());

        long totalMin = 0;
        int totalMonsters = 0;

        for(int i = 0; i < minimums.size(); i++)
        {
            totalMin = max(totalMin, minimums.at(i) - totalMonsters);
            totalMonsters += pairs.at(minimums.at(i));
        }
        cout << totalMin << endl;
    }

    return 0;
}