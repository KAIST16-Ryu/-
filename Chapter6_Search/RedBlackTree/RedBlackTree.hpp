// RedBlackTree.hpp

typedef int ElementType;

enum ColorType {RED, BLACK};

class Node
{
private:
public:
    Node *parent_;
    Node *left_;
    Node *right_;
    ColorType color_;
    ElementType data_;

    Node (ElementType _data);
};

class RedBlackTree
{
private:
public:

    Node *root_;
    Node *nil_;
    int num_node_;

    RedBlackTree (void);
    RedBlackTree (Node *_root);

    void PrintTree (void);
    void RecursivePrintTree (Node *_node, int _black_count, int _depth, int _direction);
    
    Node *SearchNode (ElementType _data);

    void RotateLeft (Node *_parent);
    void RotateRight (Node *_parent);

    void InsertNode (Node *_node);
    bool InsertNodeAsBST (Node *_node, Node *_new_node);
    void InsertHandleRedAndRed (Node *_node);
    
    Node *RemoveNode (ElementType _data);
    Node *RemoveNodeAsBST (Node *_target_node);
    Node *FindPreOrderSuccessor (Node *_target_node);
    void RemoveHandleRedAndRed (Node *_parent_node, bool _is_left);
};