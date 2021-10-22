#include <bits/stdc++.h> 
using namespace std; 


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	
    	long long ans =0;
    	int start=0,end=n-1;
    	sort(a,a+n);
    	while(start<end)
    	{
    	    if(a[start]+a[end]>0)
    	    {
    	        ans=ans+(end-start);
    	        end--;
    	    }
    	    else{
    	       start++; 
    	    }
    	}
    	return ans;
    }   
};



int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 
