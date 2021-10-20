                          TWINS PROBLEM:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,min=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        min+=a[i];
        if(min>(sum-min)){cout<<i+1;return 0;}
    }
    cout<<n;
    return 0;
}
