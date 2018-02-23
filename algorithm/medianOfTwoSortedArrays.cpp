// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Shi Rui
// Date   : 2018-02-06

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto it_1 : nums2)
        {
            if (nums1.empty())
	    {
	    	nums1 = nums2;
		break;
	    }
            
            auto it_2 = nums1.begin();
            for(;it_2 != nums1.end(); it_2++)
            {
                if (it_2 == nums1.end() - 1 && it_1 >= *it_2)
					{
						nums1.push_back(it_1);
						break;
					}
                
                if(it_1 >= *it_2)
                    continue;
                else
                {
                    nums1.insert(it_2, it_1);
                    break;
                }
            }
        }
        
        double result = 0.0;
        if(nums1.size() % 2 != 1)
        {
            result = (double)(nums1[nums1.size() / 2 -1 ] + nums1[nums1.size() / 2])/2;
        }
        else
            result = (double)nums1[nums1.size() / 2];
        
        return result;
    }
};
