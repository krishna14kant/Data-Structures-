#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class graph
{
    map<T, list<T> >l;
    public:
        void addedge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void bfs(T src)
        {
            map<T,int > visited;  // boolean
            queue<T> q;
            q.push(src);
            visited[src]=true;
            while(!q.empty())
            {
                T node= q.front();
                q.pop();
                cout<<node<<" ";
                for(int nbr: l[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        //mark that nbr as visited
                        visited[nbr]=true;
                    }
                }
            }
        }
};
int main() 
{
    graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,5);
   // g.addedge(0,3);
    g.bfs(0);  // passing source
}
/*
o/p:
0 1 2 3 4 5 
*/

