#include <queue>
#include <cmath> 
#include <memory> 
#include <cctype>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	if(a.length()==b.length())
	{
		int i=0,flag=0;
		for(i=0;i<a.length();i++)
		{
			if(a[i]!=b[a.length()-(i+1)])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"YES"<<endl;
			return 0;	
		}	
	}	
	cout<<"NO"<<endl;
	return 0;
}