//
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int cases;
	cin>>cases;
	while(cases--){
	    long n;
	    cin>>n;
	    long array[n];
	    for(long i=0;i<n;i++){
	        cin>>array[i];
	    }
	    long min = *min_element(array,array+n);
	    long max = *max_element(array,array+n);
	    if( max<0)
	        cout<<max*max<<" "<<min*min<<endl;
	   else if(min<0 && max>=0 && (abs(max)-abs(min))<0)
	        cout<<min*max<<" "<<min*min<<endl;
	    else if(min<0 && max>=0 && (abs(max)-abs(min))>0)
	        cout<<min*max<<" "<<max*max<<endl;
	   else 
	        cout<<min*min<<" "<<max*max<<endl;
	}
	return 0;
}
