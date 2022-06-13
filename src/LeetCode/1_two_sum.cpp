#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // instinct: one run through
        // put seen numbers in a map
        // take complement of current number and try to find in the set
        // return if that's the number
        
        unordered_map<int, int> seen;
        
        for(int i = 0; i < nums.size(); i++)
        {
          int complement = target - nums.at(i);
          if(seen.find(complement) != seen.end())
          {
            return {i, seen.at(complement)};
          }
          else{
            seen.emplace(nums.at(i), i);
          }
        }
        return {};
    }
};