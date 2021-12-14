/*
Name :- Atharva Kinikar
Div : SE 10
Batch : F 10
Roll No : 23241
*/
#include "dijkstra.cpp"
//driver code
int main()
{
    Dijkstra d;
    cout << "~~~~~~~~~~Dijkstra's Algorithm~~~~~~~~~~~\n";
    d.createGraph(); //creating graph
    d.display(0);    //displaying the shortest distances
    return 0;
}
