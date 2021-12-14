/*
Name :- Atharva Kinikar
Div : SE 10
Batch : F 10
Roll No : 23241
*/

#include <iostream>
#include <climits>
using namespace std;
#define V 10

//class fro algorithm
class Dijkstra
{
public:
    int graph[V][V]; //adjacency matrix for graph
    int nodes;
    string Cityname[V] = {"Pune", "Mumbai", "Nashik", "Aurangabad", "Nagar", "Solapur", "Amravati", "Kolhapur", "Jalgaon", "Latur"};
    void createGraph();
    int mindist(int[], bool[]);
    void display(int);
};