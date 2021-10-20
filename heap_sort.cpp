






 

 



#include <bits/stdc++.h>


void buildHeap(int[], int);
void heapify(int[], int, int);
void swap(int *, int *);
void print(int[], int n);

void buildHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n);
    cout << "Heap is : ";
    print(a, n);
}

void heapify(int a[], int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);   
        heapify(a, 0, i);
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[] = {20, 10, 15, 7, 26, 11};
    int n = sizeof(a) / sizeof(a[0]);

    //Build Max Heap
    buildHeap(a, n);

    //Heap sort
    heapsort(a, n);
    cout << "Sorted array is : ";
    print(a, n);
    return 0;

}
