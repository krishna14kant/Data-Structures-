#include<iostream>
using namespace std;
void linearsearch(int n,int a[],int s){
     for(int i=0;i<n;i++){
         if(a[i]==s){
             cout<<"element found at "<<i+1<<endl;
             break;
         }
     }
}
int main()
{
    int n;
    cout<<"enter the no. of elements";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    cout<<"enter the element to be searched";
    cin>>s;
    linearsearch(n,a,s);
    return 0;
}