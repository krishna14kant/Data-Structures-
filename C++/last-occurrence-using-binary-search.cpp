#include<bits/stdc++.h>
using namespace std;
void ocour(int a[],int n,int x){
        int lo=0;
        int hi=n-1;
        int mid;
        int index=-1;
        while(hi>=lo){
            mid=(hi+lo)/2;
            if(a[mid]==x){
                 lo=mid+1;
                 index=mid;
            }
            else if(a[mid]>x){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(index!=-1){
            cout<<index;
        }
        else{
            cout<<"not found";
        }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    ocour(a,n,x);
}
