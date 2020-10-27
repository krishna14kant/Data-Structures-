/*

Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.


Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

*/

//solution
#include<bits/stdc++.h>

using namespace std;
using interval = vector<int>;

bool comparator(interval a, interval b)
{
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort based on starting interval
        
        sort(intervals.begin(),intervals.end(),comparator);
        int ans=intervals.size();
        int maxEnd = 0;
        for(interval cur:intervals)
        {
            int curEnd = cur[1];
            if(curEnd <= maxEnd){
                ans--;
            }
            
            maxEnd = max(maxEnd, curEnd);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> input = {{1,4},{3,6},{2,8}};
    Solution ob;
    ob.removeCoveredIntervals(input);
    return 0;
}