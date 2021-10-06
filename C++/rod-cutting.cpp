#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int findMax(int l[],int p[],int len,int cty){
    if(cty==0 || len==0)
    return 0;
    if(dp[len][cty]!=-1)
    return dp[len][cty];

    if(l[len-1]<=cty){
        return dp[len][cty]=max(p[len-1]+findMax(l,p,len,cty-l[len-1]),findMax(l,p,len-1,cty));
    }
    else
    {
        return dp[len][cty]=findMax(l,p,len-1,cty);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    while(t--){
        int len;
        cin>>len;
        int l[len];
        int p[len];
        for(int i=0;i<len;i++)
        cin>>l[i];
        for(int i=0;i<len;i++)
        cin>>p[i];
        cout<<findMax(l,p,len,len)<<endl;
    }
    return 0;
}