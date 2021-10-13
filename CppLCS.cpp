/*LCS (Longest Common Subsequence) using DP*/
#include <bits/stdc++.h>
using namespace std;

int max(int p, int q);
int lcs( char *X, char *Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs(X, Y, m-1, n-1);
	else
		return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int p, int q)
{
	return (p > q)? p : q;
}

/* Driver code */
int main()
{
	char X[] = "HACKTOBERFEST";
	char Y[] = "GITHUB";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
	
	return 0;
}


