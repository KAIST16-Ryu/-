// Heap.cpp

#include "Heap.hpp"
#include <iostream>
#include <cstring>

using namespace std;

Heap::Heap (int _size)
{
    int capacity;
    for (capacity = 1; capacity < _size; capacity *= 2) {}
    
    this->capacity_ = capacity;
    this->size_ = 0;
    this->arr_ = new ElementType [this->capacity_];
}

Heap::~Heap (void)
{
    delete [] this->arr_;
}

void Heap::Swap (int _index_a, int _index_b)
{
    ElementType temp_data;

    temp_data = this->arr_[_index_a];
    this->arr_[_index_a] = this->arr_[_index_b];
    this->arr_[_index_b] = temp_data;

    return;
}

void Heap::ResizeBigger (void)
{
    ElementType *new_arr = new ElementType [this->capacity_ * 2];
    memmove (new_arr, this->arr_, this->capacity_);

    this->capacity_ *= 2;

    delete [] this->arr_;
    this->arr_ = new_arr;

    return;
}

void Heap::Insert (ElementType _data)
{
    if (this->size_ >= this->capacity_) {
        this->ResizeBigger ();
    }

    this->arr_[this->size_] = _data;

    int index = this->size_;
    while (true) {
        if (index == 0) {
            break;
        }
        
        if (this->arr_[index] < this->arr_[(index-1)/2]) {
            this->Swap (index, (index-1)/2);
            index = (index-1)/2;
        }
        else if (this->arr_[index] == this->arr_[(index-1)/2]) {
            cout << "Your input is already in the Heap." << endl;
            return;
        }
        else {
            break;
        }
    }
    this->size_++;
}

ElementType Heap::DeleteMin (void)
{
    if (this->size_ == 0) {
        cout << "There are no elements in the Heap." << endl;
        return 0;
    }

    this->size_--;

    ElementType min_value = this->arr_[0];
    this->arr_[0] = this->arr_[this->size_];
    this->arr_[this->size_] = 0;

    int index = 0;
    int child_index;
    ElementType temp;
    while (this->size_ >= index*2+2) {

        // find minimal children.
        child_index = index*2;

        if ( this->arr_[child_index+2] != 0 && this->arr_[child_index+2] < this->arr_[child_index+1] ) {
            if (this->arr_[child_index+2] < this->arr_[index]) {
                this->Swap (index, child_index+2);
                index = child_index+2;
            }
        }
        else if (this->arr_[child_index+1] < this->arr_[index]) {
            this->Swap (index, child_index+1);
            index = child_index+1;
        }
    }

    return min_value;
}

void Heap::PrintNodes (void)
{
    cout << "Size of the Heap: " << this->capacity_ << endl;
    cout << "Number of Elements: " << this->size_ << endl;
    for (int i = 0; i < this->size_; i++) {
        cout << this->arr_[i] << " ";
    }
    cout << endl;
    cout << "--------done--------" << endl;
    cout << endl;

    return;
}