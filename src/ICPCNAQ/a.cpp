#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long i = N;

    unordered_set<int> digits;
    int lastDigit = 0;
    int digitCount = 0;

    while( i != 0 )
    {
      digits.emplace(i % 10);
      lastDigit = i % 10;
      i /= 10;
      digitCount++;
    }


    int max = -1, min = 10;
    int smallerThanFirst = 0, largerThanFirst = 10;

    for(int j = 0; j < 10; j++)
    {
      if(!digits.count(j)){
        max = j;
        if(min == 10) min = j; 
        if(j < lastDigit){
          smallerThanFirst = j;
        }
        if(j > lastDigit){
          largerThanFirst = std::min(j, largerThanFirst);
        }
      }
    }

    if(max == -1 && min == 10)
    {
      cout << "Impossible";
      return 0; 
    }

    long long lowerAns = smallerThanFirst;
    long long higherAns = largerThanFirst;

    for(int j = 1; j < digitCount; j++){

      lowerAns = lowerAns*10 + max;
      higherAns = higherAns*10 + min;

    }

    if(lowerAns >= 0)
    {
      if(N - lowerAns == higherAns - N){
        cout << lowerAns << " " << higherAns;
      }
      else cout << ((N-lowerAns < higherAns-N) ? lowerAns : higherAns);
    }
    else cout << higherAns;


    return 0;
}