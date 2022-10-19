//Cut Paper
//https://www.codechef.com/START60D/problems/CUTPAPER


#include<algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    if(a==b){
	        cout<<1<<endl;
	        continue;
	    }
	    else if(a%b==0){
	        cout<<(a/b)*(a/b)<<endl;
	        continue;
	    }
	    float sq=1.414;
	    float d1=sq*a;
	    float d2=sq*b;
	    int f=d1/d2;
	    cout<<f*f<<endl;
	}
	return 0;
}
