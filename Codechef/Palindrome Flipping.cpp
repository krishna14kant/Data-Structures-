//FLIPPAL Starters 60

#include <iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int len;
	    cin>>len;
	    string str;
	    cin>>str;
	    int count=0;
	    int s=0;
	    int e=len-1;
	    if(len%2==0){
	        while(s<e){
	            if(str[s]!=str[e]){
	                count++;
	            }
	            s++;
	            e--;
	        }
	        if(count%2==0){
	            cout<<"YES"<<endl;
	            continue;
	        }else{
	            cout<<"NO"<<endl;
	            continue;
	        }
	    }else{
	        cout<<"YES"<<endl;
	        continue;
	    }
	   // if(len%2==0){
	   //     if(count%2==0){
	   //         cout<<"YES"<<endl;
	   //         continue;
	   //     }else{
	   //         cout<<"NO"<<endl;
	   //         continue;
	   //     }
	   // }else{
	   //     if(count%2==0){
	   //         cout<<"NO"<<endl;
	   //         continue;
	   //     }else{
	   //         cout<<"YES"<<endl;
	   //         continue;
	   //     }
	   // }
	}
	return 0;
}
