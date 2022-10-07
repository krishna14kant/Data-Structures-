int pickup(vector<int> num, int x, int ind, vector<vector<int>> &dp){
    
    if(ind==0){
        if(x%num[0]==0)
            return x/num[0];
        else
            return 1e9;
    } 
    
    if(dp[ind][x]!=0)
        return dp[ind][x];
    
    int notTake= 0 + pickup(num, x, ind-1, dp);
    
    int take=INT_MAX;
    if(num[ind]<= x)
        take= 1 + pickup(num, x-num[ind],ind,dp);
    dp[ind][x]= min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
    
    vector<vector<int>> dp(num.size(), (vector<int>(x+1, 0)));
   int ans= pickup(num, x, num.size()-1,dp);
    
    if(ans==1e9)
        return -1;
    return ans;
}
