#include <iostream>
using namespace std;


int steps = 0;

void heapify(int[], int, int);
void heapSort(int[], int);

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total steps taken: " << steps << endl;

    return 0;
}

void heapSort(int arr[], int n)
{
    steps = 0; // Reset steps counter
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // one by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);
        steps += 3; // 3 steps: swapping two elements

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;   // initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // if left child is larger than root
    if (l < n)
    {
        steps++; // Comparison step
        if (arr[l] > arr[largest])
        {
            largest = l;
        }
    }

    // if right child is larger than largest so far
    if (r < n)
    {
        steps++; // Comparison step
        if (arr[r] > arr[largest])
        {
            largest = r;
        }
    }

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        steps += 3; // 3 steps: swapping two elements

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
