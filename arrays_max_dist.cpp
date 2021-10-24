#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        cout << "Enter the Number of test cases You want\n";
        int t,n;
        cin>>t;                          //Number of Test cases
        while(t--)
        {
        cout << "Enter the length of the Array\n";
        cin>>n;
        
          int a[n], mx=0;                  //Integer array and the max distance between similiar elements in the array
          cout << "Enter Array elements\n";
          for(int i=0;i<n;i++)
            cin>>a[i];
            
          map<int,int> m;                  //Map Declaration
          
          for(int i=0;i<n;i++)
          {
              if(m.find(a[i])==m.end())
                  m[a[i]]=i;
              else
                  mx=max(mx,(i-m[a[i]]));
          }
          
         cout<<mx<<"\n";
        }
    return 0;
}
