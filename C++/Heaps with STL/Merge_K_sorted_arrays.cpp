#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int ,pair<int ,int> > node;
vector<int >merge(vector<vector<int> > arr)
{
    vector<int > result;
    priority_queue<node , vector<node> , greater<node> >pq;  //min heap
    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        node current=pq.top();
        pq.pop();
        int element =current.first;
        int x=current.second.first;
        int y=current.second.second;
        result.push_back(element);
        if(y+1< arr[x].size())
        {
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }
    return result;
}
int main()
{
	/*
    vector<vector<int> > arr{ {2,6,12,15},
                              {1,3,14,20},
                              {3,5,8,10}
                            };
    vector<int > output=merge(arr);
    for(auto x:output)
*/
    int k,n; //K is number of sorted arrays and n is no of elements in the sorted arrays. 
	cin>>k>>n;
	vector <vector <int>> arr; //Vector of Vector 
	
	for(int i = 0 ; i < k ; i++)
	{
		vector <int> v1; //Declaring a vector 
		int a; //Declaring the input 
		for(int i = 0 ; i < n ; i++)
		{
			cin>>a;
			v1.push_back(a); //Using vector function push_back to add elements 
		}
		arr.push_back(v1); //Adding the vectors to arr declared in line 34 
	}
    vector<int> output=merge(arr); //Calling merge function above to sort 
    for(auto x:output) //Printing 
    {
        cout<<x<<" ";
    }
}
