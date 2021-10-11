// Sort a given set of elements using the Quick sort method .
//  The elements can be read from a file and should be generated
//  using the random number generator.

//QUICK  SORT..............

#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
int partition(int arr[], int l, int h)
{
    //selecting first element as pivot
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j)
    {
        //until we dont get element greater than pivot increase i
        while (arr[i] <= pivot)
            i++;
        //until we dont get element less than pivot decrease j
        while (arr[j] > pivot)
            j--;
        //now swapping both elements
        if (j > i)
            swap(arr[i], arr[j]);
    }
    //finally j will point to correct position of pivot element
    swap(arr[l], arr[j]);
    return j;
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        //getting paritioned index
        int j = partition(arr, l, h);

        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}
int main()
{

    // Use current time as seed for random generator
    srand(time(0));

    cout<<"program will generate random number by itself \nwrite them to a file \nread numbers from the file and sort them using quick sort...........\n";

    //Generating random number less than or equal to 10
    int n = rand() % 10 + 1;

    //Genrating array of random numbers
    cout << "size " << n << endl;

    //creating an array
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    // open file in write mode
    ofstream write("random_numbers.txt");

    // overwriting data in file
    for (int i = 0; i < n; i++)
    {
        write << arr[i] << " ";
    }

    // closing file
    write.close();
    delete[] arr;

    // opening file in read mode
    ifstream read("random_numbers.txt");

    //array to store data from the file
    int nums[n];

    // reading data from the file
    if (read.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            read >> nums[i];
        }
        // closing file
        read.close();
    }
    else
        cerr << "Can't find input file" << endl;
    cout << "Original array is............\n";
    for (int i = 0; i < n; i++)
        cout << nums[i] << "  ";
    quicksort(nums, 0, sizeof(nums) / sizeof(int));
    cout << "\n\n*************\nprinting Sorted array......\n";
    for (auto val : nums)
        cout << val << "  ";
    return 0;
}