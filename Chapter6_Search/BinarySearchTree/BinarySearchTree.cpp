// BinarySearchTree.cpp

#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

Node::Node (ElementType _data) {
    this->Data = _data;
    this->LeftChild = NULL;
    this->RightChild = NULL;
}

BinarySearchTree::BinarySearchTree (void) {
    this->Root = NULL;
    this->Num = 0;
}

BinarySearchTree::BinarySearchTree (Node *_node) {
    this->Root = _node;
    this->Num = 1;
}

void BinarySearchTree::InsertNode (Node *_node) {
    Node *temp = this->Root;

    while (temp != NULL) {
        if (temp->Data > _node->Data) {
            if (temp->LeftChild == NULL) {
                temp->LeftChild = _node;
                return;
            }
            else temp = temp->LeftChild;
        }
        else if (temp->Data < _node->Data) {
            if (temp->RightChild == NULL) {
                temp->RightChild = _node;
                return;
            }
            temp = temp->RightChild;
        }
    }
}

void BinarySearchTree::Inorder (Node *_node, int _depth) {
    if (_node == NULL) return;
    else {
        this->Inorder (_node->LeftChild, _depth+1);

        cout << " " << _node->Data;

        this->Inorder (_node->RightChild, _depth+1);
    }
    return;
}

void BinarySearchTree::PrintTree_Inorder (void) {
    this->Inorder(this->Root, 0);
    cout << endl;
}


Node *BinarySearchTree::RemoveNode (Node *_parent, Node *_targetNode, ElementType _data) {
    Node *returnNode;
    
    // Nothing in the BST.
    if (_targetNode == NULL) {
        return NULL;
    }
    // Search successfully.
    else if (_targetNode->Data == _data) {
        // Left Node.
        if (_targetNode->LeftChild == NULL && _targetNode->RightChild == NULL) {
            if (_parent->LeftChild == _targetNode) _parent->LeftChild = NULL;
            else if (_parent->RightChild == _targetNode) _parent->RightChild = NULL;
            this->Num--;
            return _targetNode;
        }
        // Both Child Exists.
        else if (_targetNode->LeftChild != NULL && _targetNode->RightChild != NULL) {
            // Find Smallest Large Node.
            returnNode = this->RemoveRightSmallest (_targetNode, _targetNode->LeftChild);
            if (_parent->LeftChild == _targetNode) _parent->LeftChild = returnNode;
            else if (_parent->RightChild == _targetNode) _parent->RightChild = returnNode;
            this->Num--;
            return _targetNode;
        }
        // Only one child exists.
        else if (_targetNode->LeftChild == NULL) {
            returnNode = this->RemoveNode (_targetNode, _targetNode->RightChild, _targetNode->RightChild->Data);
            if (_parent->LeftChild == _targetNode) _parent->LeftChild = returnNode;
            else if (_parent->RightChild == _targetNode) _parent->RightChild = returnNode;
            this->Num--;
            _targetNode->RightChild = NULL;
            return _targetNode;
        }
        else if (_targetNode->RightChild == NULL) {
            returnNode = this->RemoveNode (_targetNode, _targetNode->LeftChild, _targetNode->LeftChild->Data);
            if (_parent->LeftChild == _targetNode) _parent->LeftChild = returnNode;
            else if (_parent->RightChild == _targetNode) _parent->RightChild = returnNode;
            this->Num--;
            _targetNode->LeftChild = NULL;
            return _targetNode;
        }
    }
    else {
        if (_targetNode->Data >_data ) {
            returnNode = RemoveNode (_targetNode, _targetNode->LeftChild, _data);
        }
        else if (_targetNode->Data < _data ) {
            returnNode = RemoveNode (_targetNode, _targetNode->RightChild, _data);
        }

        return returnNode;
    }
}

Node *BinarySearchTree::RemoveRightSmallest (Node *_parent, Node *_targetNode) {
    Node *temp = _targetNode;
    Node *parent = _parent;

    while (temp->LeftChild != NULL) {
        temp = temp->LeftChild;
        parent = temp;
    }

    if (temp->RightChild != NULL) {
        parent->LeftChild = temp->RightChild;
    }
    else parent->LeftChild = NULL;

    return temp;
}
