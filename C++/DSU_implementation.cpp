#include <bits/stdc++.h>
using namespace std;
static int r[1000];
static int par[1000];
void makeSet(int n){
  for(int i=1;i<=n;i++){
      par[i]=i;
      r[i]=0;
  }
}
int findPar(int node){
    if(node==par[node]) return node;
    return par[node]=findPar(par[node]);   //Path compression
}
void Union(int a,int b){
    int u=findPar(a);
    int v=findPar(b);
    if(r[u]<r[v]){
        par[u]=v;
    }
    else if(r[u]>r[v]){
        par[v]=u;
    }
    else{
        par[u]=v;
        r[v]++;
    }
    return;
}
int main() {
    int m,n;
    cin>>m>>n;
    makeSet(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
   return 0;
}
