#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
{ 
   int i,n,d,a[10000000],r=0,nr=0,c=0;
   cin>>n>>d;
   for(i=0;i<n;i++)
{
   cin>>a[i];
}
   if(d==1)
{
   cout<<n<<"\n";
}
else
{
   for(i=0;i<n;i++)
{
    if(a[i]>=80||a[i]<=9)
    r++;  
} 
    nr=n-r;
    while(r>=0)
{
    if(r>0)
    {
        c++;
        
    } 
   r=r-d; 
   
}
   while(nr>=0)
{
    if(nr>0)
    {
        c++;
        
    }
  nr=nr-d;
  
}
  cout<<c<<"\n";
}
   t--;
}
   return 0;
}
