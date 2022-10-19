#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int a,b,x,y;
	    cin>>a>>b>>x>>y;
	    float m = float(a)/float(x);
	    float n = float(b)/float(y);
	    
	    if(n<m){
	        cout<<"Chefina"<<endl;
	    }
	    else if(m<n){
	        cout<<"Chef"<<endl;
	    }
	    else{
	        cout<<"Both"<<endl;
	    }
	    
	    
	}
	return 0;
}
