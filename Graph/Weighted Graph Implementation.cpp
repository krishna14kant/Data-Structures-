#include<iostream>
#include<list>
#include<cstring>
#include<unordered_map>
using namespace std;
class graph
{
	//adj list
	unordered_map<string, list <pair <string, int> > > l;
	public:
		void addedge(string x, string y,bool bidir, int wt)
        {
            l[x].push_back(make_pair(y,wt));
            if(bidir)
            {
                l[y].push_back(make_pair(x,wt));
            }
        }
        void printlist()
        {
            for(auto p:l)
            {
                string city= p.first;
                list <pair <string, int> >nbrs=p.second;
                cout<<city<<"-> ";
                for(auto nbr:nbrs)
                {
                    string dest=nbr.first;
                    int dist=nbr.second;
                    cout<<dest<<" "<<dist<<",";
                }
                cout<<endl;
            }   
        }
};
int main()
{
    graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","D",true,40);
    g.addedge("A","C",true,10);
    g.addedge("C","D",true,40);
    g.addedge("A","D",false,50);
    g.printlist();
}/*
o/p:
A-> B 20,C 10,D 50,
C-> A 10,D 40,
D-> B 40,C 40,
B-> A 20,D 40,
*/
