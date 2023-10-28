#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int findVertex(int *weight,bool* visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}

void prims(int **edges,int n)
{
    int *parent=new int[n];
    int *weights=new int[n];
    bool *visited=new bool[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    parent[0]=-1;
    weights[0]=0;

    for(int i=0;i<n;i++)
    {
        int minVertex=findVertex(weights,visited,n);
    visited[minVertex]=true;
    for(int j=0;j<n;j++)
    {
        if(edges[minVertex][j]!=0 && !visited[j])
        {
            if(edges[minVertex][j] <weights[j])
            {
                weights[j]=edges[minVertex][j];
                parent[j]=minVertex;
            }
        }
     }
    }

    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
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
int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<E;i++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }

    cout<<endl;
    prims(edges,V);


    for(int i=0;i<V;i++)
    {
        delete [] edges[i];
    }

    delete  []edges;

  return 0;
}

