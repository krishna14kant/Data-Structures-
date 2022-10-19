#include<iostream>
using namespace std;
void fillarray(int a[],int n);
void displayarray(int a[],int n);
void shellsort(int a[], int n);
void swap(int &x, int &y);       //pass by reference
int main()
{
	int n;
	cout<<"Enter array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array elements"<<endl;
	fillarray(a,n);  //function calling
	cout<<"\n The array elements are ";
	displayarray(a,n);
	
	cout<<"\n The sorted array is \n";
		displayarray(a,n);	
}
void fillarray(int a[], int n){
	for(int i=0; i<=n-1; i++)
	cin>>a[i];
}
void displayarray(int a[],int n){
	for(int i=0; i<=n-1; i++)
	cout<<a[i]<<" \t ";
}	
void swap(int &x, int &y)
{
int t=x;
  x=y;
  y=t;
}
void shellsort(int a[], int n){
  int gap =n/2;
  while (gap > 0){
  	for (int i=gap;i<=n;i++)
  	{
  		int temp =a[i] , j=1;
  		while(j>=gap&&a[i-gap]>temp){
  			a[j]=a[i-gap];
  			j=j-gap;
  			
  			
		  }
		  a[j]=temp;
	  }
  }	
}


