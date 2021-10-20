#include<bits/stdc++.h>
using namespace std;
void slide(int *a ,int n,int k)
{
    vector<int> slider;
    vector<int> tot;
    int i=0,j=0,sum=0,maxi=0;
    while(j<n)
    {
        if(a[j]<0)
        {
            tot.push_back(a[j]);
        }
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(tot.size()==0)
            {
                slider.push_back(0);
            }
            else
            {
                slider.push_back(tot[0]);
            }
            if(a[i]<0)
            {
                tot.erase(tot.begin());;
            }           
            i++;
            j++;
        }
   }
   for(auto x: slider)
   {
       cout<<x<<" ";
   }

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    slide(a,n,k);
}