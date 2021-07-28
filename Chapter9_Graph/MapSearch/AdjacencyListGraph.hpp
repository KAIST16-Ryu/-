// AdjacencyListGraph.hpp
#pragma once
#include "Queue.hpp"

typedef int DataType;

class Vertex;
class Edge;
class Graph;

class Vertex
{
private:
public:
    DataType data_;
    int index_;
    bool visited_;
    Edge *adjacency_edge_;
    Vertex *next_vertex_;

    Vertex (void);
    Vertex (DataType _data);

    void AddEdge (Edge *_new_edge);
};

class Edge
{
private:
public:
    int weight_;
    Vertex *from_;
    Vertex *to_;
    Edge *next_edge_;

    Edge (Vertex *_from, Vertex *_to);
    Edge (Vertex *_from, Vertex *_to, int _weight);
};

class Graph
{
private:
public:
    Vertex *vertices_;
    int num_vertices_;

    Graph (void);
    void AddVertex (Vertex *_new_vertex);
    void PrintGraph (void);

    void DepthFirstSearch (Vertex *_vertex);
    void BreadthFirstSearch (Vertex *_vertex, Queue *_queue);
};

