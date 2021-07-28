#pragma once
// AdjacencyListGraph.cpp

#include "AdjacencyListGraph.hpp"
#include "Queue.hpp"
#include <iostream>

using namespace std;

Vertex::Vertex (void)
{
    this->data_ = -1;
    this->index_ = -1;
    this->visited_ = false;
    this->adjacency_edge_ = NULL;
    this->next_vertex_ = NULL;
}

Vertex::Vertex (DataType _data)
{
    this->data_ = _data;
    this->index_ = -1;
    this->visited_ = false;
    this->adjacency_edge_ = NULL;
    this->next_vertex_ = NULL;
}

Edge::Edge (Vertex *_from, Vertex *_to)
{
    this->weight_ = 0;
    this->from_ = _from;
    this->to_ = _to;
    this->next_edge_ = NULL;
}

Edge::Edge (Vertex *_from, Vertex *_to, int _weight)
{
    this->weight_ = _weight;
    this->from_ = _from;
    this->to_ = _to;
    this->next_edge_ = NULL;
}

void Vertex::AddEdge (Edge *_new_edge)
{
    if (_new_edge == NULL ) {
        cout << "NULL edge pointer Error." << endl;
        return;
    }

    if (this->adjacency_edge_ == NULL) {
        this->adjacency_edge_ = _new_edge;
    }
    else {
        Edge *temp_edge = this->adjacency_edge_;
        while (temp_edge->next_edge_ != NULL) {
            temp_edge = temp_edge->next_edge_; 
        }
        temp_edge->next_edge_ = _new_edge;
    }
}

Graph::Graph (void)
{
    this->vertices_ = NULL;
    this->num_vertices_ = 0;
}

void Graph::AddVertex (Vertex *_new_vertex)
{
    if (_new_vertex == NULL) {
        cout << "NULL vertex pointer Error." << endl;
        return;
    }

    if (this->vertices_ == NULL) {
        this->vertices_ = _new_vertex;
    }
    else {
        Vertex *temp_vertex = this->vertices_;
        while (temp_vertex->next_vertex_ != NULL) {
            temp_vertex = temp_vertex->next_vertex_;
        }
        temp_vertex->next_vertex_ = _new_vertex;
    }

    this->num_vertices_++;

    return;
}

void Graph::PrintGraph (void)
{
    Vertex *temp_vertex = NULL;
    Edge *temp_edge = NULL;

    temp_vertex = this->vertices_;
    while (temp_vertex != NULL) {
        cout << temp_vertex->data_ << " : ";
        temp_edge = temp_vertex->adjacency_edge_;

        while (temp_edge != NULL) {
            cout << temp_edge->to_->data_ << "[" << temp_edge->weight_ << "] ";

            temp_edge = temp_edge->next_edge_;
        }
        cout << endl;

        temp_vertex = temp_vertex->next_vertex_;
    }
}

void Graph::DepthFirstSearch (Vertex *_vertex)
{
    if (_vertex->visited_) {
        cout << "You visit visited one. raise ERROR." << endl;
        return;
    }

    cout << _vertex->data_ << " ";
    _vertex->visited_ = true;


    Vertex *temp_vertex = _vertex;
    
    for ( Edge *temp_edge = temp_vertex->adjacency_edge_; \
                temp_edge != NULL; \
                temp_edge = temp_edge->next_edge_ ) {
        
        if ( !temp_edge->to_->visited_ ) {
            this->DepthFirstSearch (temp_edge->to_);
        }
    }
}

void Graph::BreadthFirstSearch (Vertex *_vertex, Queue *_queue)
{


}