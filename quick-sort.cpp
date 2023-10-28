#include <iostream>
//bellabeen
using namespace std;
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
int main()
{
    int a[5],bil,i;
    cout<<"Program Pengurutan Quick Sort Secara Ascending\n";
    cout<<"===============================================\n";
    cout<<"Berapa banyak bilangan (max 5) : ";
    cin>>bil;
    cout<<"\nMasukkan bilangan yang belum di sorting : \n";
    
    for(i=0;i<bil;i++)
        cin>>a[i];
        
    quick_sort(a,0,bil-1);
    cout<<"Bilangan yang telah di sorting : ";
    for(i=0;i<bil;i++)
        cout<<a[i]<<" ";
    
    return 0;        
}
 
void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}
