#pragma once
// Queue.hpp
#include "AdjacencyListGraph.hpp"

typedef Vertex ElementType;

class Node;
class Queue;

class Node
{
private:
public:
    ElementType element_;
    Node *next_;

    Node (ElementType _element);
};

class Queue
{
private:
public:
    Node *head_;
    Node *tail_;
    int num_nodes;

    Queue (void);

    void Enqueue (Node *_new_node);
    Node *Dequeue (void);
};