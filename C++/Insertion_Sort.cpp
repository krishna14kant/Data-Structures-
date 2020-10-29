#include <iostream>
using namespace std;

void insertion_sort(int arr[] , int n)
{
	for (int i = 1 ; i < n ; i++)
	{
		int e = arr[i];
		//place the current element e in its right position in the sorted part
		int j = i - 1;
		while (j >= 0 and arr[j] > e)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = e;
	}
}

int main()
{
	int n;
	n = 10;
	int arr[10] = {1, 54, 34, 53, 67, 64, 678, 45, 54, 54};
	insertion_sort(arr, n);
	for (int i = 0 ; i < n ; i++)	cout << arr[i] << " ";

}



