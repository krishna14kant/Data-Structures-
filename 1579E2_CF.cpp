#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ll long long
#define endl "\n"


/*-----------------------------------------------------------------------------
------------------------------------------------------------------------------*/


void solve(){
    ll n;cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pbds st;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i==0){
            st.insert(a[i]);
        }else{
            ll up=0,down=0;
            st.insert(a[i]);
            auto it2=st.upper_bound(a[i]);
            up=st.order_of_key(a[i]);
            down=st.order_of_key(a[i]+1);
            down=st.size()-down;
            ans+=min(up,down);
            // cout<<up<<" "<<down<<endl;
        }
    }
    cout<<ans<<endl;
}


int main() {

    ll int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
