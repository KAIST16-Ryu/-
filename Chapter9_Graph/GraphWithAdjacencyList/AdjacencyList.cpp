// AdjacencyList.cpp

#include "AdjacencyList.hpp"
#include <iostream>

using namespace std;

Vertex::Vertex (ElementType _data)
{
    this->data_ = _data;
    this->index = -1;
    this->visited_ = 0;

    this->next_vertex_ = NULL;
    this->adjacency_list_ = NULL;    
}

void Vertex::AddEdge (Edge *_edge)
{
    if (this->adjacency_list_ == NULL) {
        this->adjacency_list_ = _edge;
    }
    else {
        Edge *temp_edge = this->adjacency_list_;
        while (temp_edge->next_edge_ != NULL) {
            temp_edge = temp_edge->next_edge_;
        }
        temp_edge->next_edge_ = _edge;
    }

    return;
}

Edge::Edge (Vertex *_start, Vertex *_end, int _weight)
{
    this->weight_ = _weight;
    this->next_edge_ = NULL;

    this->start_ = _start;
    this->end_ = _end;
}

Graph::Graph (void)
{
    this->vertex_count_ = 0;
    this->vertices_ = NULL;   
}

Graph::~Graph (void)
{
    delete [] this->vertices_;
}

void Graph::AddVertex (Vertex *_vertex)
{

    if (this->vertices_ == NULL) {
        this->vertices_ = _vertex;
    }
    else {
        Vertex *temp_vertex = this->vertices_;
        while (temp_vertex->next_vertex_ != NULL) {
            temp_vertex = temp_vertex->next_vertex_;
        }
        temp_vertex->next_vertex_ = _vertex;
    }

    this->vertex_count_++;

    return;
}

void Graph::PrintGraph (void)
{
    Vertex *temp_vertex = NULL;
    Edge *temp_edge = NULL;

    temp_vertex = this->vertices_;
    while (temp_vertex != NULL) {
        cout << (char)temp_vertex->data_ << " : ";
        temp_edge = temp_vertex->adjacency_list_;
        while (temp_edge != NULL) {
            cout << (char)temp_edge->end_->data_ << "[" << temp_edge->weight_ << "] ";

            temp_edge = temp_edge->next_edge_;
        }
        cout << endl;

        temp_vertex = temp_vertex->next_vertex_;
    }

    return;
}