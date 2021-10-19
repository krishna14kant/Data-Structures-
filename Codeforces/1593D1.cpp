//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int,int>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    IOS
    int n,mn=INT_MAX;
    cin>>n;
    vector<unsigned int>v;
    for (int i = 0; i < n; i++)
    {
        li temp;
        cin>>temp;
        if(li<0)
        if(mn>temp)mn=temp;
        v.push_back(temp);
    }for (int i = 0; i < n; i++)
    {
        if(v[i]>mn)v[i]-=mn;
    }
//     result = arr[0]
// For i = 1 to n-1
//    result = GCD(result, arr[i])
    int result=v[0];
    for (int i = 1; i < n; i++)
    {
        /* code */
        result=gcd(result,v[i]);
    }
    cout<<result<<endl;
    
    

    return 0;
}