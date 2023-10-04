#include<bits/stdc++.h>
using namespace std;
class Solution{

    public:
    long long trappingWater(int arr[], int n){
        long long s=0,e=n-1;
        long long lm=0,rm=0;
        long long sum=0;
        while(s<e)
        {
            if(arr[s]<=arr[e])
            {
                if(arr[s]>=lm)lm=arr[s];
                else sum+=lm-arr[s];
                s++;
            }
            else
            {
                if(arr[e]>=rm)rm=arr[e];
                else sum+=rm-arr[e];
                e--;
            }
        }
        return sum;
    }
};


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
    
        cin >> n;
        
        int a[n];
        
    
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
    
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
