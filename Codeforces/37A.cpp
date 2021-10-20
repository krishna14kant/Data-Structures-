//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int,int>
int main()
{
    IOS
    int n;
    cin>>n;
    int a[1001]={0};
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        a[temp]++;
    }
    int max=0,ct=0;
    for (int i = 0; i < 1001; i++)
    {
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]!=0)ct++;
    }
    cout<<max<<" "<<ct;
    
    

    return 0;
}