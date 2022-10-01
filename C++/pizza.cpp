class Solution {
public:
    int solve(int index, int endt , vector<int> &slices, int n, vector<vector<int>>& dp)
    {
            if(n==0 || index>endt)
                return 0;
        if(dp[index][n]!=-1)
            return dp[index][n];
        
        int tak = slices[index]+solve(index+2,endt,slices,n-1,dp);
        int nt = 0 + solve(index+1,endt, slices,n,dp);
        
        return dp[index][n]= max(tak,nt);
    }
    int maxSizeSlices(vector<int>& slices) {
        
        
        int k = slices.size();
        vector<vector<int>>dp1(k,vector<int>(k,-1));
        int s0 = solve(0,k-2,slices,k/3,dp1);
        vector<vector<int>>dp(k,vector<int>(k,-1));
        int s1 = solve(1,k-1,slices,k/3,dp);
        
        return max(s0,s1);
    }
};
