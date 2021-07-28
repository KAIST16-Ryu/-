// Main.cpp

#include "AdjacencyList.hpp"
#include <iostream>

using namespace std;

int main (void)
{
    // Create Undirected graph with adjacency list.
    Graph graph_;

    Vertex *v1 = new Vertex ((ElementType) '1');
    Vertex *v2 = new Vertex ((ElementType) '2');
    Vertex *v3 = new Vertex ((ElementType) '3');
    Vertex *v4 = new Vertex ((ElementType) '4');
    Vertex *v5 = new Vertex ((ElementType) '5');

    graph_.AddVertex (v1);
    graph_.AddVertex (v2);
    graph_.AddVertex (v3);
    graph_.AddVertex (v4);
    graph_.AddVertex (v5);

    v1->AddEdge (new Edge (v1, v2, 0));
    v1->AddEdge (new Edge (v1, v3, 0));
    v1->AddEdge (new Edge (v1, v4, 0));
    v1->AddEdge (new Edge (v1, v5, 0));

    v2->AddEdge (new Edge (v2, v1, 0));
    v2->AddEdge (new Edge (v2, v3, 0));
    v2->AddEdge (new Edge (v2, v5, 0));

    v3->AddEdge (new Edge (v3, v1, 0));
    v3->AddEdge (new Edge (v3, v2, 0));

    v4->AddEdge (new Edge (v4, v1, 0));
    v4->AddEdge (new Edge (v4, v5, 0));

    v5->AddEdge (new Edge (v5, v1, 0));
    v5->AddEdge (new Edge (v5, v2, 0));
    v5->AddEdge (new Edge (v5, v4, 0));

    graph_.PrintGraph ();

    return 0;
}