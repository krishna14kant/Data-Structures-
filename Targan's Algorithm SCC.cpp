#include<bits/stdc++.h>
#define fo(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
using namespace std;

vi g[1001];
bool vis[1001] , onStack[1001];
int in[1001] , low[1001];
stack<int> st;

int timer = 1 , SCC = 0;

void dfs(int node)
{
	vis[node] = 1;
	in[node] = low[node] = timer++;
	onStack[node] = true;
	st.push(node);
	
	for(int u : g[node])
	{
		if((vis[u] == true) && (onStack[u] == true))
		{
			low[node] = min(low[node] , in[u]);
		}
		else
		if(vis[u] == false)
		{
			dfs(u);
			
			if(onStack[u] == true)
			low[node] = min(low[node] , low[u]);
		}
	}
	
	if(in[node] == low[node])
	{
		SCC++;
		cout<<"SCC #"<<SCC<<endl;
		
		int u;
		
		while(1)
		{
			u = st.top();
			st.pop() , onStack[u] = false;
			cout<<u<<" ";
			
			if(u == node) break;
		}
		cout<<endl;
	}
}

int main()
{
	int n , m, a , b;
	cin>>n>>m;
	
	fo(i , m) cin>>a>>b , g[a].pb(b);
	
	fo(i , n) vis[i] = onStack[i] = false;
	
	fo(i , n)
	if(vis[i] == false) dfs(i);
	
}

