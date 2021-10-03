#include<iostream>
#include<math.h>
using namespace std;

void generateSubsets(int n, char set[]) {
    for(int i=0; i<(1<<n); i++) {
        cout<<i<<") ";
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                cout<<set[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {

    int n;
    cout<<"Enter number of elements in set: ";
    cin>>n;

    char set[n];
    cout<<"Enter elements of set: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>set[i];
    }

    generateSubsets(n, set);
    

    return 0;
}