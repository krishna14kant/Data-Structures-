//Given an integer array nums, return all the triplets [nums[i],nums[j], nums[k]] 
//such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Notice that the solution set must not contain duplicate triplets.

#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define all(x) x.begin(), x.end()
using namespace std;

vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
}
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  vector<int> num={1,-1,0,4,5};
  vector<vector<int>> res=threeSum(num);
    for(int i=0;i<res.size();i++){
  	for(int j=0;j<3;j++){
  		cout<<res[i][j]<<" ";
  	}
  	cout<<endl;
  }
  return 0;
}
