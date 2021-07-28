// BinarySearchTree.hpp

typedef int ElementType;

class Node
{
private:
public:
    ElementType Data;
    Node *LeftChild;
    Node *RightChild;

    Node (ElementType _data);
};

class BinarySearchTree
{
private:
    void Inorder (Node *_node, int _depth);
public:
    Node *Root;
    int Num;

    BinarySearchTree (void);
    BinarySearchTree (Node *_node);

    void InsertNode (Node *_node);
    void PrintTree_Inorder (void);
    Node *RemoveNode (Node *_parent, Node *_targetNode, ElementType _data);
    Node *RemoveRightSmallest (Node *_parent, Node *_targetNode);
};