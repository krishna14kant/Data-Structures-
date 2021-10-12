#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"


void solve(){
    ll n;cin>>n;
    char a[2][n];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    ll flag=0;
    if(a[0][0]=='1'){
        cout<<"NO"<<endl;
        return;
    }else{
        for(int i=0;i<n;i++){
            if(a[0][i]=='1'&&a[1][i]=='1'){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
}


int main() {
    ll int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
