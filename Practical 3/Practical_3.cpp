#include <iostream>
using namespace std;

void max_heapify(int arr[], int n, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // Check left child
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // Check right child
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not the root
    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;

        // Heapify the affected subtree
        max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }

    // Heap Sort
    for (int j = n - 1; j > 0; j--)
    {
        // Move largest element to the end
        int t = arr[0];
        arr[0] = arr[j];
        arr[j] = t;

        // Heapify remaining heap
        max_heapify(arr, j, 0);
    }
}

void display(int arr[], int n)
{
    

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {5, 6, 9, 7, 6, 56};
	cout<<"/------------------- max heap sort----------------/"<<endl;
    int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted array: ";
    display(arr, size);
    
    heapSort(arr, size);
    
	cout << "Sorted array: ";
    display(arr, size);

    return 0;
}
