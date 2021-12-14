/*
Name :- Atharva Kinikar
Div : SE 10
Batch : F 10
Roll No : 23241
*/

#include "graph.h"

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int Dijkstra::mindist(int dist[], bool set[])
{
    // Initialize min value
    int min = INT_MAX;
    int index;
    for (int i = 0; i < nodes; i++)
    {
        if (set[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Dijkstra::display(int sr)
{ //sr is source vertex of the graph

    // The output array.  dist[i] will hold the shortest
    // distance from src to i
    int dist[V];

    // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    bool set[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
        set[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[sr] = 0;

    cout << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << "Shortest Path\n";
    cout
        << "~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "City\t\tDistance" << endl;
    for (int i = 0; i < nodes - 1; i++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. m is always equal to src in the first iteration.
        int m = mindist(dist, set);

        // Mark the picked vertex as processed
        set[m] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int j = 0; j < nodes; j++)
        {
            if (!set[j] && graph[m][j] &&
                dist[m] + graph[m][j] < dist[j])
                dist[j] = dist[m] + graph[m][j];
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << Cityname[i] << ":\t\t" << dist[i] << endl;
    }
}

//function to create graph using adjacency matrix
void Dijkstra::createGraph()
{
    cout << "Enter number of cities you want from 1-10:" << endl;
    cin >> nodes;
    if (nodes < 1 || nodes > 10)
        cout << "\nInvalid Input";
    cout << "Enter the cost adjacency matrix:" << endl;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            cin >> graph[i][j];
    }
}