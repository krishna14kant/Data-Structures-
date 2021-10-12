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
    multiset<pair<ll,ll>,greater<pair<ll,ll>>>st;
    for(int i=0;i<n;i++){
        if(a[i]!=0)
            st.insert({a[i],i+1});
    }
    if(st.size()<=1){
        cout<<0<<endl;
        return;
    }

    ll k=0;
    
    vector<pair<ll,ll>>me;
    while(st.size()!=0){
        if(st.size()<=1){
            break;
        }
        auto it1=st.begin();
        auto it2=st.begin();it2++;
        // cout<<it1->first<<" "<<it2->first<<endl;
        k++;
        me.push_back({it1->second,it2->second});
        ll val1=it1->first;
        ll val2=it2->first;
        if(val1-1==0&&val2-1==0){
            
        }else if(val1-1==0){
            st.insert({val2-1,it2->second});
        }else if(val2-1==0){
            st.insert({val1-1,it1->second});
        }else{
            st.insert({val1-1,it1->second});
            st.insert({val2-1,it2->second});
        }
        st.erase(it1);
        st.erase(it2);
    }
    cout<<k<<endl;
    for(int i=0;i<me.size();i++){
        cout<<me[i].first<<" "<<me[i].second<<endl;
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
