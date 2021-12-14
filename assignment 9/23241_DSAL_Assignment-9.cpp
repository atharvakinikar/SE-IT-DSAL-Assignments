//Name:Atharva Kinikar
//Roll no.:23241
//Div : Se 10
//Batch: F10
//Assignment no.:9
#include "heapsort.cpp"

//driver code

int main()
{
    //creating object of heap class
    Heap ob;

    //declaring integers n and i
    int n, i;

    cout << "Heap Sort\n";
    cout << "Enter number of elements in your array: ";

    //taking input from user for number of elements
    cin >> n;

    //creating an array of size n
    int array[n];

    cout << "Enter your array elements:\n";

    //taking input for numbers
    for (i = 0; i < n; i++)
    {
        cout << "Number " << i + 1 << " is:";
        cin >> array[i];
    }
    ob.Heap_Sort(array, n);   //calling heap_sort function
    ob.Print_Array(array, n); //calling print array function to display sorted array
    return 0;
}