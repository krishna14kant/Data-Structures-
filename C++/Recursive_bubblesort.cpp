/* C++ program for recursive implementation of Bubble sort */
#include <bits/stdc++.h>
using namespace std;

// A function for bubble sort
void Bubble_Sort(int array[], int N)
{
	// First case
	if (N == 1)
		return;

	/* One pass of bubble sort. After
	 this pass, the largest element
	is bubbled (or moved) to end.*/
	for (int i=0; i<N-1; i++)
		if (array[i] > array[i+1])
			swap(array[i], array[i+1]);

	// Largest element is fixed,
	
    // recur for remaining array
	Bubble_Sort(array, N-1);
}

/* Function to print an array */
void Print_Array(int array[], int N)
{
	for (int i=0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
}

// Driver function for testing the above.
int main()
{
	int array[] = {32,74,43,86,94,12,10,764};
	int N = sizeof(array)/sizeof(array[0]);
	Bubble_Sort(array, N);
	printf("Sorted array : \n");
	Print_Array(array, N);
	return 0;
}
