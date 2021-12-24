#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = 0; 

    cin >> n;

    while(n--)
    {
        
        vector<long> minimums;
        vector<int> monsterCounts;
        int totalMonsters = 0;
        int caves = 0;
        cin >> caves;
        while(caves--)
        {
            int monsters = 0;
            cin >> monsters;
            monsterCounts.push_back(monsters);
            totalMonsters += monsters;
            long minimum = 0;
            cin >> minimum;
            minimum++;
            monsters--;
            int i = 1;
            while(monsters--)
            {
                long nextMonster = 0;
                cin >> nextMonster;
                minimum = max(minimum, nextMonster - i + 1);
                i++;
            }
            minimums.push_back(minimum);
        }
        long totMin = 0;
        long smallestMin = minimums.at(0);
        for(int i = 0; i < minimums.size(); i++)
        {
            smallestMin = min(minimums.at(i), smallestMin);
            totMin = max(totMin, minimums.at(i) - (totalMonsters - monsterCounts.at(i)));
        }
        totMin = max(smallestMin, totMin);
        cout << totMin << endl;
    }

    return 0;
}