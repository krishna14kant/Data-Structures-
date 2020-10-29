#include<iostream>
using namespace std;
void binarysearch(int a[],int s,int e,int x){
    while(s<e){
    int m = (s+e)/2;
    if(a[m]==x){
        cout<<"element found at "<<m+1;
        return ;
    }
    else if(a[m]>x){
        binarysearch(a,s,m-1,x);
    }
    else if(a[m]<x){
        binarysearch(a,m+1,e,x);
    }
    }
}
int main(){
    int n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j]){
                int t = a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    int x;
    cout<<"enter the element to be searched"<<endl;
    cin>>x;
    binarysearch(a,0,n-1,x);
}