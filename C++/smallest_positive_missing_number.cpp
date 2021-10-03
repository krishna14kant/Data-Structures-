#include<iostream>
#include<climits>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    const int N = 1e6 + 2;
    bool check[N];
    for(int i=0; i<N; i++)
        check[i] = false;

    for(int i=0; i<n; i++) {
        if(arr[i]>0) {
            check[arr[i]] = true;
        }
    }

    int ans = 0;
    for(int i=1; i<N; i++){
        if(check[i]==false){
            ans = i;
            cout<<"Smallest positive missing number is: "<<ans<<endl;
            break;
        }
    }
    return 0;
}