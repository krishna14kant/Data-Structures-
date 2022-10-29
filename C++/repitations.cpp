#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,count=1,x=0;
	
	std::string name;
	cin>>name;
	n=name.length();
	
	if(n>=1 && n<= 100000){
	
	
	
	for(int i=0;i<n;i++){
		
		if (name[i]==name[i+1] && i<n-1)count++;
		else {
			if(count>x) {
			            x=count;
		                  }
						 count=1;
	          }
	
	
	}
	cout<<x;
}
