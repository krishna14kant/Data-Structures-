#include <iostream>
using namespace std;

void selection_sort(int arr[] , int n)
{
	for(int i=0 ; i<n-1 ; i++)
	{
		int min_index = i;
		for(int j=i ; j<n ; j++)
		{	
			if(arr[j] < arr[min_index])	min_index = j;
			// this thing is much efficient rather than swap or storing in 
			// temp everytime because swap is expensive function
			// in this we donot have to use to swap everytime in second lopp

		}
		swap(arr[i],arr[min_index]);
	}
}

int main()
{
	int n;
	n=10;
	int arr[10]={1,54,34,53,67,64,678,45,54,54};
	selection_sort(arr,n);
	for(int i=0 ; i<n ; i++)	cout<<arr[i]<<" ";

}
