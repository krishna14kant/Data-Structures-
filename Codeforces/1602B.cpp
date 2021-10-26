Problem Link:
https://codeforces.com/contest/1602/problem/B

My submission:
https://codeforces.com/contest/1602/submission/133002587

Code:

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vi vector<ll>
#define vp vector<pi>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define POB pop_back 
#define f(i,x,z) for(ll i=x;i<z;i++)
#define debug(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define setall(x,a) memset(x, a, sizeof(x))
#define INF 1000000000000000003 
#define mathpi 3.141592653589793238 
#define F first;
#define S second;
#define vpair vector<pair<ll,ll>>
#define vpairs vector<pair<string,string>>
#define tin tuple<ll,ll,ll>
#define rev(i,x,z) for(ll i=x;i>=z;i--)  
#define ld long double 
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n"; 
#define print_pair(v) for(auto x:v){cout<<x.first<<" "<<x.second<<" ";}cout<<"\n"; 
#define reverse(v) reverse(v.begin(),v.end()) 
#define nl "\n"
vi v;
void sieve(ll n)
{
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) 
    {
        if (is_prime[i] && (long long)i * i <= n) 
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    f(i,0,n)
    {
        if(is_prime[i]==1)
        {
            v.pb(i);
        }
    }
}
ll binaryexponention(ll a,ll b)
{
	ll result=1,md=1000000007;
	while(b>0)
	{
		if(b%2==1)
		{
			result*=a;
		}
		a*=a;
		b/=2;
	}
	return result;
}

void cf_round()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll x=0,y=0;
        x+=c/2;
        y+=c/2;
        if(c%2!=0)
        {
            x+=3;
        }
        if(x>y)
        {
            if(b>0)
            {
                if(a%2!=0)
                {
                    cout<<0<<nl;
                }
                else{
                    cout<<1<<nl;
                }
            }
            else{
                if(a%2==0)
                {
                    cout<<1<<nl;
                }
                else{
                    cout<<0<<nl;
                }
            }
        }
        else{

        }
    }
}
int main()
{
    // freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);// Input and output clearance
    cin.tie(0);
    // cf_round();   
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        vi v(2001,0);
        vi v4;
        f(i,0,n)
        {
            cin>>a[i];
            v4.pb(a[i]);
            v[a[i]]++;
        }
        vector<vi>v1;
        ll last=0;
        v1.pb(v4);
        while(true)
        {
            ll cnt=0;
            vi v2;
            last++;
            vi v3=v;
            f(i,0,n)
            {
                ll prev=a[i];
                a[i]=v3[a[i]];
                v[prev]--;
                v[a[i]]++;
                if(prev=a[i])
                {
                    cnt++;
                }
                v2.push_back(a[i]);
            }
            v1.pb(v2);
            if(v4==v2)
            {
                break;
            }
            v4=v2;
        }
        ll q;
        cin>>q;
        f(i,0,q)
        {
            ll x,y;
            cin>>x>>y;
            if(y<v1.size())
            {
                vi v5=v1[y];
                // print(v5);
                cout<<v5[x-1]<<nl;
            }
            else{
                cout<<v1[v1.size()-1][x-1]<<nl;
            }
        }
    }

}
//  think brutforce again
// make templates shortcut small
