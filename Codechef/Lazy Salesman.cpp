#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int n,w;
        cin>>n>>w;
        int a[n];
        for(int i=0; i<=n-1; i++){
            cin>>a[i];
        }
        sort(a,a+n,greater<int>{});
        int sum = 0;
        
        for(int i = 0; i<=n-1;i++){
            sum+=a[i];
            if(sum>=w){
                cout<<n-(i+1)<<endl;
                break;
            }
            
        }
        
        
    }
	
	return 0;
}
