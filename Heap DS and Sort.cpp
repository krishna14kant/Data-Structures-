//Heap Data Structure and Sorting (Max Heap)
#include <bits/stdc++.h>
using namespace std;

void Heapify(int *a, int n, int i) {
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && a[l]>a[largest])
	largest = l;
	
	if(r<n && a[r]>a[largest])
	largest = r;
	
	if(largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		
		Heapify(a, n, largest);
	}
}

void HeapSort(int ar[], int n) {
	//Heapify
	for(int i=n/2;i>=0;i--) {
		Heapify(ar, n, i);
	}
	
	for(int i=n-1;i>=0;i--) {
		int temp = ar[0];
		ar[0] = ar[i];
		ar[i] = temp;
		
		Heapify(ar,i, 0);
	}
}

void Display(int *a, int n){
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
int main()
{
	int ar[]={10,56,2,9,11,121,7,4,65,63,1,119};
	int n=sizeof(ar)/sizeof(ar[0]);
	HeapSort(ar,n);
	
	Display(ar, n);
}
