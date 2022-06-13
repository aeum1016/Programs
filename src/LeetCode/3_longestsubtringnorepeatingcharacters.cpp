#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // instinct: one pass using a map, start and end
        // go tthrough the string
        // if the character is found in the map, check the spot
        // if the spot is higher than the start, update the start and the end
        // then update the spot in the map

      int start = 0, end = 0;
      unordered_map<char, int> last_seen;
      int largest_substring = 0;

      for(int i = 0; i < s.length(); i++)
      {
        if(last_seen.find(s.at(i)) != last_seen.end())
        {
          int spot = last_seen.at(s.at(i));
          if(spot >= start)
          {
            start = spot+1;
          }
        }
        end = i;
        last_seen[s.at(i)] = i;
        largest_substring = max(largest_substring, end - start + 1);
      }
      return largest_substring;
    }
};