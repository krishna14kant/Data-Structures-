#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
Question link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
*/

/*
ALGO:
Given a word w = c1c2c3c4c5 (we shall write it as w{1,5})
-   To find all permutations of a word w{1,5}, fix
    the character at the left most index of w{1,5}, this character can be any character after
    the leftmost index). 
-   Now, after fixing index 1, find all possible permutations of w{2,5}
    (how? just the way we did for w{1,5}).
    (i.e., fix the character at index 2, and find all possible permutations of w{3,5})
-   Keep doing this until we reach w{5,5}. When we reach there, print it out.

IDEA EXPLAINED:
-   We're basically trying to obtain all possible permutations of w, by filling each 
    index in the string starting from left at every step.
-   We are basically trying to fill each index starting from the left and generate a 
    possible permutation of w.
-   INDUCTION HYPOTHESIS:
    At step i,
    By now, we've already filled the w{0,i-1} part of the permutation that is being obtained.
-   BASIS:
    F(i,r,w) : if l==r, print w. (This is exactly when we've filled all positions of the
    permutation and found it).
-   INDUCTION:
    F(i,r,w):
    Fix the character at i th position (this can be any character
    from w{i,n}) and find F(i+1,r,w). 

*/

void FindPermutations(string st, int l, int r)
{
    if(l==r)
    {
        cout << st << " ";
        return;
    }
    
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(st[l],st[i]);
            FindPermutations(st,l+1,r);
            swap(st[l],st[i]);
        }    
    }
    
}

int main() {
	int tc;
	cin >> tc;
	for(int t=0; t<tc; t++)
	{
	    string st;
	    cin >> st;
	    int n = st.size();
	    FindPermutations(st,0,n-1);
	    cout << endl;
	    
	}
	return 0;
}