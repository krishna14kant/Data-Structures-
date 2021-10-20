//1. Two Sum Leetcode Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> hash;
     vector<int> ans;
        for(int i = 0;i<nums.size();i++)
            if(hash.count(target-nums[i])>0)
            {
                ans.push_back(hash[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }   
            else
                hash[nums[i]] = i;
        return ans;
    }
};