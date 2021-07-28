#pragma once
// Queue.cpp

#include "Queue.hpp"
#include <iostream>
#include <cstring>

using namespace std;

Node::Node (ElementType _element)
{
    this->element_ = _element;
    this->next_ = NULL;
}

Queue::Queue (void)
{
    this->head_ = NULL;
    this->tail_ = NULL;
    this->num_nodes = 0;
}

void Queue::Enqueue (Node *_new_node)
{
    // An empty queue.
    if (this->num_nodes == 0) {
        this->head_ = _new_node;
        this->tail_ = _new_node;
        this->num_nodes++;

        return;
    }
    else {
        _new_node->next_ = this->head_;
        this->head_->next_ = _new_node;
        this->num_nodes++;

        return;
    }
}

Node *Queue::Dequeue (void)
{
    Node *dequeue_node = NULL;

    // An empty queue.
    if (this->num_nodes == 0) {
        cout << "An empty queue 'Dequeue Error'." << endl;
        return NULL;
    }
    else if (this->num_nodes == 1) {
        dequeue_node = this->head_;
        this->head_ = NULL;
        this->tail_ = NULL;
        this->num_nodes--;

        return dequeue_node;
    }
    else {
        Node *temp_node = this->head_;
        while (temp_node->next_ != this->tail_) {
            temp_node = temp_node->next_;
        }

        dequeue_node = this->tail_;
        temp_node->next_ = NULL;
        this->tail_ = temp_node;
        this->num_nodes--;

        return dequeue_node;
    }
}