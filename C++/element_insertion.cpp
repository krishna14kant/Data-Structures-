#include <iostream>
using namespace std;

int main(){

// to insert an element into an array

int arr[50],i,element,t,index;

cout<<"enter the size of your array: ";
cin>>t;

cout<<"enter "<<t<<" array element: ";
for(i=0;i<t;i++){
    cin>>arr[i];
    
}
  cout<<endl;
    cout<<"enter element to insert: "<<endl;
    cin>>element;
    
    cout<<"enter position you want to insert element into: ";
    cin>>index;

for(i = t; i>=index;i--){
    arr[i] = arr[i-1];
}
    arr[i] = element;
    t++;

for(i=0;i<t;i++){
    cout<<arr[i]<<endl;
}

}
