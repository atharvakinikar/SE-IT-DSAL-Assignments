//Name:Atharva Kinikar
//Roll no.:23241
//Div : Se 10
//Batch: F10
//Assignment no.:9

//header file

#include <iostream>
using namespace std;

//class heap
class Heap
{
public:
    Heap(){};                                      //constructor
    void Heapify(int array[], int root, int size); //heapify function
    void Heap_Sort(int array[], int size);         //heap sort function for sorting
    void Build_Heap(int array[], int size);        //function to build heap
    void Print_Array(int array[], int size);       //printing the result array
};