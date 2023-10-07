#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0)); // seeding the rand with system time
	int t= rand() % 10 + 1; // printing number between
							// range 1 to 100
	cout<<t<<"\n";// number of testcase
	for(int i=0;i<t;i++){
		int n=rand()%100+1;
		cout<<n<<"\n"; // random array size
		for(int j=0;j<n;j++)cout<<rand()%100+1<<" "; // random array
		cout<<"\n";
	}
	return 0;
}