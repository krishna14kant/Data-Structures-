/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the 
same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

//solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        //Typical Dutch National Flag Problem
        
        // 2 0 2 1 1 0
        // 3 way partitioning
        int low=0,mid=0,high=nums.size()-1;
        
        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high--]);
            }
                 
        }
    }
};

int main()
{
    vector<int> input = {2,0,2,1,1,0};
    Solution obj;
    obj.sortColors(input);
    for(int i=0;i<6;i++)
    {
        cout<<input[i]<<" ";
    }
    return 0;
}