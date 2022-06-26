#include <vector>


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

      // should be O(log(m+n))
      // Use the smaller vector of the two.
      // Perform a binary search, using the complement of the other vector
      
      if(nums1.size() >= nums2.size())
      {
        int low = 0;
        int high = nums1.length();

        while(true)
        {
          int mid = low + ((high - low) / 2);
          
          if(nums1.at(mid) < nums2.at(num))
        }
      }
        
    }
};