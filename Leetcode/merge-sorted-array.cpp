//https://leetcode.com/problems/merge-sorted-array


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=m;
        for(int i=0;i<n;i++){
            nums1[j]=nums2[i];
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }
};
