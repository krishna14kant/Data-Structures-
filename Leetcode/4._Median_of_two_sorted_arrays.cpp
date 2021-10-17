// 4. Median of Two Sorted Arrays Solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        double ans;
        int i = 0, j = 0;
        while (i<nums1.size() && j <nums2.size())
        {
        if (nums1[i] < nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
        }

        while (i <nums1.size())
            merged.push_back(nums1[i++]);

        while (j < nums2.size())
            merged.push_back(nums2[j++]);
    
    
    if(merged.size()%2==0)
    {
        ans = merged.at(merged.size()/2) + merged.at((merged.size()/2)-1);
        ans = ans/2;
    }
    else
    {
        ans = merged.at(merged.size()/2);
    }
    return ans;
    }
};