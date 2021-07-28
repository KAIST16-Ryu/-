// OpenAddressing.cpp

#include "OpenAddressing.hpp"
#include <iostream>
#include <cstring>

using namespace std;

HashNode::HashNode (const char *_key, const char *_value)
{
    this->key_ = (char *) _key;
    this->value_ = (char *)_value;
}

HashNode::~HashNode (void)
{
    delete [] this->key_;
    delete [] this->value_;
}

HashTable::HashTable (int _arr_size)
{
    this->arr_size_ = _arr_size;
    this->num_nodes = 0;
    this->hash_table_ = new HashNode * [_arr_size] {NULL, };
}

HashTable::~HashTable (void)
{
    delete [] this->hash_table_;
}

void HashTable::AddNode (HashNode *_new_node)
{
    // Check whether rehashing is need or not.
    if (this->num_nodes * 2 >= this->arr_size_) {
        cout << "Rehashing start. Extend hash table size as double." << endl;
        this->ReHash ();
        cout << "Rehashed. New table size is :" << this->arr_size_ << endl;
    }

    // Get key_value form the key.
    int hash_table_index = this->Hash (_new_node->key_);
    int hash2_increment = this->Hash2 (_new_node->key_);

    int index = hash_table_index;
    int i = 1;
    while (this->hash_table_[index] != NULL) {
        cout << "Collision occured. I will process 'Open Addressing'." << endl;
        cout << "Node: " << _new_node->key_ << ", Value: " << _new_node->value_ \
            << ", address: " << hash_table_index << ", incremented address: " \
            << (index + hash2_increment) % this->arr_size_ << endl;

        index = (index + hash2_increment) % this->arr_size_;
        i++;
    }

    this->hash_table_[index] = _new_node;
    this->num_nodes++;

    cout << "Key(" << _new_node->key_ << ") entered at address (" << index << ")." << endl;
    return;
}

int HashTable::Hash (const char *_key)
{
   int hash_value = 0;

   for ( int i = 0; i < strnlen (_key, KEY_MAX_LEN); i++ ) {
       hash_value = (hash_value<<3) + _key[i];
   }
   hash_value %= this->arr_size_;

    return hash_value;
}

int HashTable::Hash2 (const char *_key)
{
   int hash2_value = 0;

   for ( int i = 0; i < strnlen (_key, KEY_MAX_LEN); i++ ) {
       hash2_value = (hash2_value << 2) + _key[i];
   }

    hash2_value %= (this->arr_size_-3);

    return (hash2_value + 1);
}

void HashTable::ReHash (void)
{
    int origin_arr_size = this->arr_size_;
    this->arr_size_ *= 2;

    HashNode **new_hash_table = new HashNode * [this->arr_size_] {NULL, };

    for ( int i = 0; i < origin_arr_size; i++ ) {
        if (this->hash_table_[i] != NULL) {
            ReHashAddNode (this->hash_table_[i], new_hash_table);
        }
    }

    delete [] this->hash_table_;
    this-> hash_table_ = new_hash_table;

    return;
}

void HashTable::ReHashAddNode (HashNode *_node, HashNode **_new_table)
{
    int new_table_index = this->Hash (_node->key_);
    int hash2_increment = this->Hash2 (_node->key_);

    int index = new_table_index;
    int i = 1;
    while (_new_table[index] != NULL) {
        cout << "Collision occured. I will process 'Open Addressing'." << endl;
        cout << "Node: " << _node->key_ << ", Value: " << _node->value_ \
            << ", address: " << new_table_index << ", incremented address: " \
            << (index + hash2_increment) % (this->arr_size_) << endl;

        index = (index + hash2_increment) % (this->arr_size_);
        i++;
    }

    _new_table[index] = _node;
    cout << "Key(" << _node->key_ << ") entered at address (" << index << ")." << endl;

    return;
}

const char *HashTable::GetNodeValue (const char *_key)
{
    int hash_table_index = this->Hash (_key);
    int hash2_increment = this->Hash2 (_key);

    int index = hash_table_index;
    int i;
    char *value = NULL;

    while (this->hash_table_[index] != NULL) {
        if (this->hash_table_[index]->key_ == _key ) {
            value = (char *)this->hash_table_[index]->value_;
            break;
        }

        index = (index + hash2_increment) % this->arr_size_;
        i++;
    }

    if (value == NULL) {
        return NULL;
    }
    else return value;
}

void HashTable::PrintHashTable (void)
{
    cout << "Hash Table Start." << endl;
    for ( int i = 0; i < this->arr_size_; i++ ) {
        if (this->hash_table_[i] != NULL) {
            cout << "index: " << i << ", key: " << this->hash_table_[i]->key_ << ", value: " << this->hash_table_[i]->value_ << endl;
        }
    }
    cout << "Hash Table End." << endl;

    return;
}

static int Pow (int _base, int _exponent)
{
    int exponential = 1;
    for (int i = 1; i <= _exponent; i++ ) {
        exponential *= _base;
    }

    return exponential;
}