Problem Link:
https://codeforces.com/contest/1602/problem/C

My Submission:
https://codeforces.com/contest/1602/submission/133014334

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
string decimal_to_binary(ll a)
{
    // all binary numbers are in 32 bit decimal form
    ll val=a;
    string s="";
    ll cnt=0;
    while(val!=0)
    {
        ll remainder=val%2;
        val/=2;
        if(remainder==0)
        {
            s+='0';
        }
        else{
            s+='1';
        }
        cnt++;
    }
    f(i,cnt,32)
    {
        s+='0';
    }
    reverse(s);
    return s;
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
        vi v(32,0);
        f(i,0,n)
        {
            cin>>a[i];
            string s=decimal_to_binary(a[i]);
            f(i,0,s.length())
            {
                if(s[i]=='1')
                {
                    v[i]++;
                }
            }
        }
        vi ans;
        f(i,1,n+1)
        {
            ll cnt=0;
            f(j,0,32)
            {
                if(v[j]%i==0)
                {
                    cnt++;
                }
            }
            if(cnt==32)
            {
                ans.pb(i);
            }
        }
        print(ans);

    }

}
//  think brutforce again
// make templates shortcut small
