// Test_BinarySearchTree.cpp

#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

int main (void) {
    
    Node *TempNode;

    /* Create New BinarySearchTree. */
    BinarySearchTree BST(new Node (123));
    
    /* Add Node to the tree. */
    BST.InsertNode (new Node(22));
    BST.InsertNode (new Node(9918));
    BST.InsertNode (new Node(424));
    BST.InsertNode (new Node(17));
    BST.InsertNode (new Node(3));

    BST.InsertNode (new Node(98));
    BST.InsertNode (new Node(34));

    BST.InsertNode (new Node(760));
    BST.InsertNode (new Node(317));
    BST.InsertNode (new Node(1));

    /* Print Tree. */
    BST.PrintTree_Inorder ();

    /* Remove Specific Node. */
    cout << "Removing 98 ..." << endl;

    TempNode = BST.RemoveNode (NULL, BST.Root, 98);
    delete TempNode;

    BST.PrintTree_Inorder ();

    /* Insert Node Node. */
    cout << "Inserting 111 ..." << endl;
    BST.InsertNode (new Node(111));

    BST.PrintTree_Inorder ();    
    cout << endl;

    return 0;
}