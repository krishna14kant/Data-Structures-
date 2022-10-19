#include <iostream>
using namespace std;

int main() 
{
    int t,i,n,k;
	cin >> t;
	while (t--)
	{
	    cin >> n >>k;
	    int d[n];
	    int f=0;
	    for (i=0;i<n;i++)
	    {
	    cin >> d[i];
	    if (d[i]>k)
	    f++;
	    }
	    cout << f << endl;
	}
	return 0;
}
