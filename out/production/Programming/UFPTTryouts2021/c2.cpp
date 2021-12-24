#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = 0; 

    cin >> n;

    while(n--)
    {
        int caves = 0;
        vector<long long> caveMinimums;
        vector<int> caveMonsters;
        int totalMonsters = 0;
        long long lowestMin = INT_MAX;
        long long totalMin = 0;
        cin >> caves;
        while(caves--)
        {
            int monsters = 0;
            long long caveMin = 0;
            cin >> monsters;
            caveMonsters.push_back(monsters);
            totalMonsters += monsters;
            int i = 0;
            while(monsters--)
            {
                long long nextMonster = 0;
                cin >> nextMonster;
                long long monsterMin = nextMonster + 1 - i;
                i++;
                caveMin = max(monsterMin, caveMin);                
            }
            lowestMin = min(lowestMin, caveMin);
            caveMinimums.push_back(caveMin);
        }
        for(int i = 0; i < caveMinimums.size(); i++)
        {
            long long localMin = caveMinimums.at(i) - (totalMonsters - caveMonsters.at(i));
            totalMin = max(localMin, totalMin);
        }
        totalMin = max(totalMin, lowestMin);
        cout << totalMin << endl;
    }

    return 0;
}