#include<iostream>
using namespace std;

int binary(int odd[], int start, int end, int num) {
    if (start <= end) {
        int m = (start + end)/2;

        if (odd[m] == num) {
            return 1;
        }
        if (odd[m] > num) {
            return binary(odd, start, m-1, num);
        }
        if (odd[m] < num) {
            return binary(odd, m+1, end, num);
        }
    }
    return 0;
}

int main() {
    int odd[] = {3,9,7,11,15,13,5,19,17,21,27,25,29,23};
    int a, f=0;

    cout<<"Enter a number to search in array: ";
    cin>>a;

    int len = sizeof(odd)/sizeof(odd[0]);

    for(int i = 0; i<len; i++) {
        int f2 = 0; 
        for(int j = 0; j<len-i-1; j++) {
            if(odd[j] > odd[j+1]) {
                odd[j] = odd[j] + odd[j+1];
                odd[j+1] = odd[j] - odd[j+1];
                odd[j] = odd[j] - odd[j+1];
                f2 = 1;
            }
        }
        if(f2==0) {
            break;
        } 
    }
    
    f = binary(odd, 0, len-1, a);

    if(f==1) {
        cout<<"Search Successful element found";
    }

    else {
        cout<<"Element not found";
    }

    return 0;
}
