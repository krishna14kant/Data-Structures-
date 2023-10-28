#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= high; j = j + i) {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

set<int> segmentedSieve(int low, int high)
{
    bool prime[high - low + 1];
    memset(prime, true, sizeof(prime));
 
    vector<int> chprime;
    fillPrimes(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);      
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }

    set<int> primes;
   
    for (int i = low; i <= high; i++) {
        if (prime[i - low] == true) {
            primes.insert(i);
        }
    }
    return primes;
}