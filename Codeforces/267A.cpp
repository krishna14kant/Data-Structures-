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
    int t;
    cin>>t;
    while(t--)
    {
        li a,b;
        cin>>a>>b;
        li ct=0;
         if(a>b)swap(a,b);
        while(b>=a&&a!=0){
            li r=(b-a)/a;
            ct+=1+r;
            b=b-a*(1+r);
            
            if(a>b)swap(a,b);
        }
        cout<<ct<<endl;
    }

    return 0;
}