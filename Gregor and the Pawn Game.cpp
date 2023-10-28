Question link: - https://codeforces.com/contest/1549/problem/B


Solution: -
#include<bits\stdc++.h>
using namespace std;
int32_t main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a ,b;
        cin>>a>>b;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(b[i]=='1'){
                if(a[i]=='0') cnt++;
                else{
                    if(a[i-1]=='1'){
                        cnt++;
                        a[i-1]='0';
                    }
                    else if(a[i+1]=='1'){
                        cnt++;
                        a[i+1]='0';
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
