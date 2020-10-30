#include<bits/stdc++.h>
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define endl "\n"
#define vll vector<ll>
#define vlll vector<vll>
#define all(x) x.begin(),x.end()
ll power(ll x, ll y, ll p) { 
    ll res = 1;    x = x % p;  
    while(y > 0) {
        if(y & 1) res = (res*x) % p; 
        y = y>>1;    x = (x*x) % p; 
    } return res; 
}
bool cmp(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    if(a.first==a.second)
    {
        return (a.second>b.second);
    }
    return (a.first<b.first);
}
const int M=3e5 + 5;
const int N=1e5+5;
vector<ll>adj[M];
vector<ll>trans[M];
vector<bool>vis(N,0);
vector<ll>ord,scc;
ll mod=1e9 + 7;
ll a[N];
ll n,m,ans=0,ch=1;
void dfs(ll u)
{
    vis[u]=1;
    for(ll i: adj[u])
    {
        if(!vis[i])
        dfs(i);
    }
    ord.pb(u);
}
void dfs1(ll u)
{
    vis[u]=1;
    for(ll i: trans[u])
    {
        if(!vis[i])
        dfs1(i);
    }
    scc.pb(u);
}
inline void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        trans[v].pb(u);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++)
    vis[i]=0;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[ord[n-i]])
        {
            map<ll,ll>mp;
            scc.clear();
            dfs1(ord[n-i]);
            ll p=1e18;
            for(ll j=0;j<scc.size();j++)
            {
                //cout<<scc[j]<<" ";
                mp[a[scc[j]]]++;
                p=min(p,a[scc[j]]);
            }
            ans=(ans+p);
            ch=(ch*mp[p])%mod;
            //cout<<endl;
        }
    }
    cout<<ans<<" "<<ch<<endl;
    
}
int main()
{
    Imposter
    
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        
    }
    return 0;
}