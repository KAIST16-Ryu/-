#pragma once
// Main.cpp

#include "AdjacencyListGraph.hpp"
#include "Queue.hpp"
#include <iostream>

using namespace std;

int main (void)
{
    int mode = 0;
    Graph graph_;

    Vertex *v1 = new Vertex (1);
    Vertex *v2 = new Vertex (2);
    Vertex *v3 = new Vertex (3);
    Vertex *v4 = new Vertex (4);
    Vertex *v5 = new Vertex (5);
    Vertex *v6 = new Vertex (6);
    Vertex *v7 = new Vertex (7);

    graph_.AddVertex (v1);
    graph_.AddVertex (v2);
    graph_.AddVertex (v3);
    graph_.AddVertex (v4);
    graph_.AddVertex (v5);
    graph_.AddVertex (v6);
    graph_.AddVertex (v7);

    v1->AddEdge (new Edge (v1, v2, 0));
    v1->AddEdge (new Edge (v1, v3, 0));

    v2->AddEdge (new Edge (v2, v4, 0));
    v2->AddEdge (new Edge (v2, v5, 0));

    v3->AddEdge (new Edge (v3, v4, 0));
    v3->AddEdge (new Edge (v3, v6, 0));

    v4->AddEdge (new Edge (v4, v5, 0));
    v4->AddEdge (new Edge (v4, v7, 0));

    v5->AddEdge (new Edge (v5, v7, 0));

    v6->AddEdge (new Edge (v6, v7, 0));

    cout << "Enter Traversal Mode (0:DFS, 1:BFS) : ";
    cin >> mode;

    if (mode == 0) {
        cout << "DFS(Depth First Search)." << endl;
        graph_.DepthFirstSearch (graph_.vertices_);
    }
    else {
        cout << "BFS(Breadth First Search)." << endl;
        Queue *queue_ = new Queue;
        graph_.BreadthFirstSearch (graph_.vertices_, queue_);
    }

    return 0;
}