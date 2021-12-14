//Name:Atharva Kinikar
//Roll no.:23241
//Div : Se 10
//Batch: F10
//Assignment no.:9
#include "heap.h"

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Heap::Heapify(int array[], int root, int size)
{
    //largest=root
    //Initialize largest as root
    int left = 2 * root + 1, largest;
    int right = left + 1, temp;
    //If left child is larger is larger than root
    if (left < size && array[left] > array[root])
        largest = left;
    else
        largest = root;
    //If right child is largest so far
    if (right < size && array[right] > array[largest])
        largest = right;
    //If largest is not root
    if (largest != root)
    {
        temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        //Recursively heapify the affected sub-tree
        Heapify(array, largest, size);
    }
}

void Heap::Build_Heap(int array[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
        Heapify(array, i, size);
}

// main function to do heap sort
void Heap::Heap_Sort(int array[], int size)
{
    //Build heap(rearrange array)
    Build_Heap(array, size);
    //One by one extract an element from here
    int temp, i;

    for (i = size - 1; i > 0; i--)
    {
        //Move current root to end
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        //call max heapify on the reduced heap
        Heapify(array, 0, i);
    }
}

// Function to print elements of array
void Heap::Print_Array(int array[], int size)
{
    cout << "\nSorted Array is: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}