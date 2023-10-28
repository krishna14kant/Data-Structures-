#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"


void solve(){
    ll n;cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deque<ll>d;
    for(int i=0;i<n;i++){
        if(d.size()==0){
            d.push_back(a[i]);
        }else{
            if(a[i]<d.front()){
                d.push_front(a[i]);
            }else{
                d.push_back(a[i]);
            }
        }
    }
    for (auto it=d.begin();it!=d.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


int main() {

    ll int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
