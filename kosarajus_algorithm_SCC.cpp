//C is subset of vertex set such that there exists a path from u to v for all u,v in C in directed graph
//In condensation graph, SCC acts as vertex
//graph and ransposed graph have same SCC
//Ci and Cj are SCC and there is a path from Ci to Cj then out[Ci]>out[Cj]
//Condensation graph is acyclic
// A directed acyclic graph has atleast 1 node with indegree 0

//Run dfs on graph and assign outtime o each node, then sort according to outtime of nodes
//node with highest outtime is that with 0 indegree

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define pb push_back
#define pp pop_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define endl '\n'
#define F first
#define S second
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define to(n) to_string(n)
#define low(v, n) lower_bound(v.begin(), v.end(), n) - v.begin()
#define upp(v, n) upper_bound(v.begin(), v.end(), n) - v.begin()
#define mod 1000000007
#define mex 100005
vl v[mex];
ll vis[mex];
vl vtranspose[mex]; //adjaceny list for transposed graph

vl order; //storing nodes in order of outtime
vl scc;

void dfs(ll n)
{
    vis[n] = 1;

    for (auto child : v[n])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
    order.pb(n);
}

void dfs1(ll n) //for transposed graph
{
    vis[n] = 1;

    for (auto child : vtranspose[n])
    {
        if (vis[child] == 0)
        {
            dfs1(child);
        }
    }
    scc.pb(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, a, b;
        cin >> n >> m;

        f(i, 1, n + 1)
        {
            vis[i] = 0;
            v[i].clear();
            vtranspose[i].clear();
        }
        order.clear();

        f(i, 1, m + 1)
        {
            cin >> a >> b;
            v[a].pb(b);
            vtranspose[b].pb(a); //for transposed graph
        }

        f(i, 1, n + 1)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }

        f(i, 1, n + 1)
        {
            vis[i] = 0;
        }

        f(i, 1, n + 1)
        {
            if (vis[order[n - i]] == 0) //checking from last
            {
                scc.clear();
                dfs1(order[n - i]);
            }
        }
    }

    return 0;
}