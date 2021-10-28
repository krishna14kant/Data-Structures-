#include<iostream>
using namespace std;

void display(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void insersion_sort(int arr[], int n)
{
	int temp;
	for(int i=1; i<n; i++)
	{
		temp = arr[i];
		for(int j=i-1; j>=0; j--)
		{
			if(arr[j]>temp)
			{
				arr[j+1]=arr[j];
				arr[j]=temp;
			}

			else
			{
				arr[j+1]=temp;
				break;
			}
		}
	}
}

int main()
{
	int A[] = {8, 5, 7, 3, 2, 4, 2};
	int n = sizeof(A)/sizeof(int);
	display(A, n);
	selection_sort(A, n);
	display(A, n);
	return 0;
}
