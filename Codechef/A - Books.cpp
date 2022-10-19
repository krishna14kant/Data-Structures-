#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int a[n];
	    int b[n] = {0};
	    
	    for(int i = 0; i<=n-1;i++){
	        cin>>a[i];
	    }
	    
	    
	    for(int i = 0; i<=n-1;i++){
	        int count = 0;
	        for(int j =1; j<=n-1;j++){
	            if(a[j]>a[i]){
	                count++;
	            }
	            b[i] = count;
	            
	        }
	        
	        if(count==0){
	            break;
	        }
	        
	    }
	    
	    for(int k = 0; k<=n-1;k++){
	        cout<<b[k]<<" ";
	    }
	    
	    cout<<endl;
	    
	}
	return 0;
}
