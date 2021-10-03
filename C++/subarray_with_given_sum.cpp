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

    int S, sum=0;
    cout<<"Enter Sum: ";
    cin>>S;

    
    // // METHOD 1
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         sum += arr[j];
    //         if(sum == S) {
    //             cout<<"Index: "<<i+1<<" "<<j+1<<endl;
    //             cout<<"\nContinuous subarray is: ";
    //             for(int k=i; k<=j; k++)
    //                 cout<<arr[k]<<" ";
    //             break;
    //         }
    //         if (sum>S)
    //             break;
    //     }
    //     if(sum==S)
    //         break;
    //     cout<<endl;
    //     sum = 0;    
    // }


    // METHOD 2
    int st=-1, en=-1;
    int j=0, i=0;
    while(j<n && sum+arr[j]<=S) {
        sum += arr[j];
        j++;
    }
    if (sum==S) {
        cout<<"Index: "<<i+1<<" "<<j;
        return 0;
    }

    while(j<n) {
        sum += arr[j];
        while(sum>S) {
            sum -= arr[i];
            i++;
        }
        if(sum==S) {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<"Index: "<<st<<" "<<en;
    
    return 0;
}