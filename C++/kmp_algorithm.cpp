#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define REP(i,k,n) for (int i = k ; i < n; i++)
#define REPD(i,k,n) for (int i = k; i >= n; i--)
#define all(v) v.begin(),v.end() 
#define SZ(x) ((int)(x).size())
#define br cout <<"\n";
// bool cmp( pair<int,int> a , pair<int,int> b ){
//     if( a.first == b.first )
//         return (a.second > b.second);
//     return a.first < b.first ;
// }
const int MOD = 1000000007;
const int INF = 1e18;

// C++ program for implementation of KMP pattern searching
// algorithm
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int j = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else // (pat[i] != pat[j])
        {
            
            if (j != 0) {
                j = lps[j - 1];
                //i does not change
            }
            else // if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout<<"Found pattern at index "<< i - j;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]


// Driver program to test above function
int32_t main()
{   
    char txt[] = "AAAAAARAR";  // give any input 
    char pat[] = "AAAR;
    KMPSearch(pat, txt);
    return 0;
}
 
