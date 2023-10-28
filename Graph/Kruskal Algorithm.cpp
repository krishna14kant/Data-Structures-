#include <iostream>
using namespace std;
#include<bits/stdc++.h>
class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2)
{
    return  e1.weight<e2.weight;
}

int findParent(int v,int *Parent)
{
    if(Parent[v]==v)
    {
        return v;
    }
    return findParent(Parent[v],Parent);
}

void Kruskal(Edge *input,int n,int E)
{
    sort(input,input+E,compare);
    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count<n-1)
    {
        Edge currentEdge=input[i];
        int sp=findParent(currentEdge.source,parent);
        int dp=findParent(currentEdge.dest,parent);
        if(sp!=dp)
        {
            output[count]=currentEdge;
            count++;
            parent[sp]=dp;
        }
        i++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(output[i].source <output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself

  */
    Edge *input=new Edge[E];
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;

    }
    Kruskal(input,V,E);

  return 0;
}
