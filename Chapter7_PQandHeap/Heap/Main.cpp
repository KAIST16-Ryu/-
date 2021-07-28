// Main.cpp

#include "Heap.hpp"
#include <iostream>

using namespace std;

int main (void) {

    Heap *heap_ = new Heap (10);

    heap_->Insert (12);
    heap_->Insert (87);
    heap_->Insert (111);
    heap_->Insert (34);
    heap_->Insert (16);
    heap_->Insert (75);

    heap_->PrintNodes ();

    heap_->DeleteMin ();
    heap_->PrintNodes ();

    heap_->DeleteMin ();
    heap_->PrintNodes ();

    heap_->DeleteMin ();
    heap_->PrintNodes ();

    heap_->DeleteMin ();
    heap_->PrintNodes ();

    heap_->DeleteMin ();
    heap_->PrintNodes ();

    return 0;
}