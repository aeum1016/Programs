#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// Width = ceil(9/16 * t * P); t = characters, P = font size;
// P = 8 + ceil(40*(cw-4)/(cmax-4)); where cw is the number of occurrences;
// 10 pt between words

int main()
{
  int width, words; 
  int cloud = 1;
  while(scanf("%d %d\n", &width, &words) != EOF)
  {
    if(!width && !words) break;
    map<string, int> wordFreqs;
    int maxFreq = -1;
    while(words--)
    {
      string word; int freq;
      cin >> word >> freq;
      if(freq >= 5) 
      {
        wordFreqs.emplace(word, freq);
        maxFreq = fmax(maxFreq, freq);
      }
    }

    int totalHeight = 0;

    int rowHeight = 0;
    int rowWidth = 0;
    for(auto it = wordFreqs.begin(); it != wordFreqs.end(); it++)
    {
      int fontSize = 8 + ceil(40.0 * (it->second-4) / (maxFreq-4));
      int wordWidth = ceil(9.0/16.0 * it->first.size() * fontSize);

      if(rowWidth == 0)
      {
        rowWidth += wordWidth;
        rowHeight = fmax(rowHeight, fontSize);
      }
      else if(rowWidth + 10 + wordWidth <= width)
      {
        rowWidth += 10 + wordWidth;
        rowHeight = fmax(rowHeight, fontSize);
      }
      else
      {
        totalHeight += rowHeight;
        rowWidth = wordWidth;
        rowHeight = fontSize;
      }
    }
    totalHeight += rowHeight;
    cout << "CLOUD " << cloud << ": " << totalHeight << endl;
    cloud++;
  }
  return 0;
}