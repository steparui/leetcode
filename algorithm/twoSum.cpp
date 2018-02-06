class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        for(int i = 0; i < nums.size();i++)
        {
           for(int j = 0; j < nums.size(); j++)
           {
               if(i == j) continue;
               if(target == nums[i] + nums[j])
               {
                   temp.push_back(i);
                   temp.push_back(j);
                   return temp;
               }
           }
        }
        return temp;
    }
};
