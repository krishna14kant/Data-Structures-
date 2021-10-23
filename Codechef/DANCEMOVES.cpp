#include <bits/stdc++.h>
using namespace std;


int main() {
	// code goes here
	int T;
	scanf("%d",&T);
	while(T--){
	    int x,y;
	    cin>>x>>y;
	    if(y>=x){
	        int diff=y-x;
	    if(diff%2==0){
	        cout<<diff/2<<endl;
	    }
	    else{
	        cout<<diff/2+2<<endl;
	    }
	    }
	    else{
	        int diff=x-y;
	    
	        cout<<diff<<endl;
	    
	   
	    }
	    
	    
	}
	return 0;
}
