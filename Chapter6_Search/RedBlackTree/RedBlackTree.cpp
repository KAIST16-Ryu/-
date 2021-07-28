// RedBlackTree.cpp

#include "RedBlackTree.hpp"
#include <iostream>

using namespace std;

Node::Node (ElementType _data)
{
    this->parent_ = NULL;
    this->left_ = NULL;
    this->right_ = NULL;
    this->color_ = RED;
    this->data_ = _data;
}

RedBlackTree::RedBlackTree (void)
{
    this->nil_ = new Node (-1);
    this->nil_->color_ = BLACK;

    this->root_ = this->nil_;

    this->num_node_ = 0;
}

RedBlackTree::RedBlackTree (Node *_root)
{
    this->root_ = _root;
    this->root_->color_ = BLACK;

    _root->left_ = this->nil_;
    _root->right_ = this->nil_;

    this->num_node_ = 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedBlackTree::PrintTree (void)
{
    if (this->num_node_ == 0) {
        cout << "Nothing in the RedBlackTree." << endl;
    }
    else {
        cout << this->root_->data_ << " " << (this->root_->color_?"BLACK":"RED") << " [X,-1]";
        if (this->root_->left_ == this->nil_ && this->root_->right_ == this->nil_) {
            cout << " ---------- 1" << endl;
        }
        else {
            cout << endl;
            this->RecursivePrintTree (this->root_->left_, 1, 1, 0);
            this->RecursivePrintTree (this->root_->right_, 1, 1, 1);
        }
    }
}

// 0 for Left, 1 for Right for variable _direction.
void RedBlackTree::RecursivePrintTree (Node *_node, int _black_count, int _depth, int _direction)
{
    // If _node is NIL node.
    if (_node == this->nil_) {
        return;
    }

    // Else.
    if (_node->color_ == BLACK) {
        _black_count++;
    }
    for (int i = 0; i < _depth; i++) {
        cout << "  ";
    }

    if (_node->left_ == this->nil_ && _node->right_ == this->nil_) {
        cout << _node->data_ << " " << (_node->color_?"BLACK":"RED") << " [" << (_direction?'R':'L')
            << "," << _node->parent_->data_ << "] ---------- " << _black_count << endl;
        return;
    }
    else {
        cout << _node->data_ << " " << (_node->color_?"BLACK":"RED") << " [" << (_direction?'R':'L')\
            << "," << _node->parent_->data_ << "]" << endl;

        this->RecursivePrintTree (_node->left_, _black_count, _depth+1, 0);
        this->RecursivePrintTree (_node->right_, _black_count, _depth+1, 1);
    }
}

Node *RedBlackTree::SearchNode (ElementType _data)
{
    Node *temp_node = this->root_;
    if (temp_node == NULL) {
        return NULL;
    }
    
    while ( temp_node != NULL) {
        // Find the target _data.
        if (temp_node->data_ == _data) {
            return temp_node;
        }
        // Target data is bigger than the node data.
        else if (temp_node->data_ < _data) {
            temp_node = temp_node->right_;
        }
        // Target data is smaller than the node data.
        else if (temp_node->data_ > _data) {
            temp_node = temp_node->left_;
        }
        // Cannot find target data.
        else if (temp_node == NULL) {
            return NULL;
        }
    }

    return NULL;
}

void RedBlackTree::RotateLeft (Node *_parent)
{
    Node *right_child = _parent->right_;

    _parent->right_ = right_child->left_;

    if (right_child->left_ != this->nil_) {
        right_child->left_->parent_ = _parent;
    }

    right_child->left_ = _parent;
    right_child->parent_ = _parent->parent_;

    if (_parent->parent_ == NULL) {
        this->root_ = right_child;
    }
    else {
        if (_parent->parent_->left_ == _parent) {
            _parent->parent_->left_ = right_child;
        }
        else {
            _parent->parent_->right_ = right_child;
        }
    }

    _parent->parent_ = right_child;
}

void RedBlackTree::RotateRight (Node *_parent)
{
    Node *left_child = _parent->left_;

    _parent->left_ = left_child->right_;

    if (left_child->right_ != this->nil_) {
        left_child->right_->parent_ = _parent;
    }

    left_child->right_ = _parent;
    left_child->parent_ = _parent->parent_;

    if (_parent->parent_ == NULL) {
        this->root_ = left_child;
    }
    else {
        if (_parent->parent_->left_ == _parent) {
            _parent->parent_->left_ = left_child;
        }
        else {
            _parent->parent_->right_ = left_child;
        }
    }

    _parent->parent_ = left_child;
}

void RedBlackTree::InsertNode (Node *_node)
{
    if (this->num_node_ == 0) {
        _node->color_ = BLACK;
        _node->left_ = this->nil_;
        _node->right_ = this->nil_;

        this->root_ = _node;
        this->num_node_++;

        return;
    }

    if ( this->InsertNodeAsBST (this->root_, _node) ) {
        // Rule, "The color of the children of the parent node with color red are black." broke.
        this->InsertHandleRedAndRed (_node);
    }
}

bool RedBlackTree::InsertNodeAsBST (Node *_node, Node *_new_node)
{
    if (_new_node->data_ < _node->data_) {
        if (_node->left_ == this->nil_) {
            _new_node->left_ = this->nil_;
            _new_node->right_ = this->nil_;
            _new_node->parent_ = _node;

            _node->left_ = _new_node;

            this->num_node_++;
            
            return true;
        }
        else {
            this->InsertNodeAsBST (_node->left_, _new_node);
        }
    }
    else if (_new_node->data_ > _node->data_) {
        if (_node->right_ == this->nil_) {
            _new_node->left_ = this->nil_;
            _new_node->right_ = this->nil_;
            _new_node->parent_ = _node;

            _node->right_ = _new_node;

            this->num_node_++;

            return true;
        }
        else {
            this->InsertNodeAsBST (_node->right_, _new_node);
        }
    }
    else {
        cout << "Overlapped value in the RedBlackTree. Not Inserted." << endl;
        return false;
    }
}

void RedBlackTree::InsertHandleRedAndRed (Node *_node) {
    // Arrive at root, the end.
    if (_node == this->root_) {
        this->root_->color_ = BLACK;
        return;
    }

    if (_node->parent_->color_ == RED) {
        Node *grandpa = _node->parent_->parent_;
        Node *uncle = NULL;

        // Parent is "Left Child".
        if (grandpa->left_ == _node->parent_) {
            uncle = grandpa->right_;

            // Parent is "Left Child" & Uncle is "RED"
            if (uncle->color_ == RED) {
                _node->parent_->color_ = BLACK;
                uncle->color_ = BLACK;
                
                grandpa->color_ = RED;

                this->InsertHandleRedAndRed(grandpa);
            }
            // Parent is "Left Child" & Uncle is "BLACK".
            else {
                // Parent is "Left Child" & Uncle is "BLACK" & I am "Right".
                // Rotate and make the same case as I am "Left".
                if (_node->parent_->right_ == _node) {
                    this->RotateLeft (_node->parent_);
                }
                else {
                    _node = _node->parent_;
                }

                // Now all case become ...
                // Parent is "Left Child" & Uncle is "BLACK" & I am "Left".
                this->RotateRight (grandpa);

                grandpa->color_ = RED;
                _node->color_ = BLACK;
                _node->left_->color_ = RED;
            }
        }
        // Parent is "Right Child".
        else {
            uncle = grandpa->left_;

            // Parent is "Right Child" & Uncle is "RED".
            if (uncle->color_ == RED) {
                _node->parent_->color_ = BLACK;
                uncle->color_ = BLACK;

                grandpa->color_ = RED;

                this->InsertHandleRedAndRed(grandpa);
            }
            // Parent is "Right Child" & Uncle is "BLACK".
            else {
                // Parent is "Right Child" & Uncle is "BLACK" & I am "Left".
                // Rotate and make the same case as I am "Right".
                if (_node->parent_->left_ == _node) {
                    this->RotateRight (_node->parent_);
                }
                else {
                    _node = _node->parent_;
                }

                // Now all case become ...
                // Parent is "Right Child" & Uncle is "BLACK" & I am "Right".
                this->RotateLeft(grandpa);

                grandpa->color_ = RED;
                _node->color_ = BLACK;
                _node->right_->color_ = RED;
            }
        }
    }
}

Node *RedBlackTree::RemoveNode (ElementType _data)
{
    Node *obsolete_node = this->SearchNode (_data);
    Node *deleted_node = NULL;

    // There are no node with _data.
    if (obsolete_node == NULL) {
        return NULL;
    }

    // Find _data node.
    else {
        deleted_node = this->RemoveNodeAsBST (obsolete_node);
        
        // Do for RedBlackTree.
        return deleted_node;
    }

    return NULL;
}

Node *RedBlackTree::FindPreOrderSuccessor (Node *_target_node) {
    Node *temp_node = _target_node;
    while (temp_node->left_ != this->nil_) {
        temp_node = temp_node -> left_;
    }

    return temp_node;
}

Node *RedBlackTree::RemoveNodeAsBST (Node *_target_node)
{
    bool is_left = false;
    // Target node has both 2 children.
    if (_target_node->left_ != this->nil_ && _target_node->right_ != this->nil_) {
        Node *successor = this->FindPreOrderSuccessor (_target_node->right_);

        _target_node->data_ = successor->data_;
        return this->RemoveNodeAsBST (successor);
    }
    // Target node has 1 child node.
    else if (!(_target_node->left_ == this->nil_ && _target_node->right_ == this->nil_)) {
        if (_target_node->left_ != this->nil_) {
            if (_target_node->parent_->left_ == _target_node) {
                is_left = true;
                _target_node->parent_->left_ = _target_node->left_;
            }
            else _target_node->parent_->right_ = _target_node->left_;

            _target_node->left_->parent_ = _target_node->parent_;
            this->num_node_--;

            if (_target_node->color_ == RED) {
                return _target_node;    
            }
            else if (_target_node->left_->color_ == RED ) {
                _target_node->left_->color_ == BLACK;
                return _target_node;
            }
            else {
                // Handle for RedBlackTree Exception.
                this->RemoveHandleRedAndRed(_target_node->parent_, is_left);
                return _target_node;
            }
        }
        else if (_target_node->right_ != this->nil_) {
            if (_target_node->parent_->left_ == _target_node) {
                is_left = true;
                _target_node->parent_->left_ = _target_node->right_;
            }
            else _target_node->parent_->right_ = _target_node->right_;

            _target_node->right_->parent_ = _target_node->parent_;
            this->num_node_--;

            if (_target_node->color_ == RED) {
                return _target_node;
            }
            else if (_target_node->right_->color_ == RED) {
                _target_node->right_->color_ = BLACK;
                return _target_node;
            }
            else {
                // Handle for RedBlackTree Exception.
                this->RemoveHandleRedAndRed(_target_node->parent_, is_left);
                return _target_node;
            }
        }
        else {
            // You should not arrive here.
            return NULL;
        }
    }
    // Target node is a leaf node.
    else {
        if (_target_node->parent_->left_ == _target_node) {
            is_left = true;
            _target_node->parent_->left_ = this->nil_;
        }
        else _target_node->parent_->right_ = this->nil_;

        this->num_node_--;
        
        // Handle for RedBlackTree Exception.
        if (_target_node->color_ != RED) {
            this->RemoveHandleRedAndRed(_target_node->parent_, is_left);
        }

        return _target_node;
    }
}

void RedBlackTree::RemoveHandleRedAndRed (Node *_parent_node, bool _is_left)
{
    // Both Target node and its Sibling is "BLACK".
    if (_parent_node->left_->color_ == BLACK && _parent_node->right_->color_ == BLACK) {
        // Target node is "Left" node.
        if (_is_left) {
            Node *sibling = _parent_node->right_;
            if (sibling->left_->color_ == BLACK && sibling->right_->color_ == BLACK) {
                if (_parent_node->color_ == RED) {
                    _parent_node->color_ == BLACK;
                    sibling->color_ = RED;
                }
                else {
                    sibling->color_ = RED;

                    if (_parent_node->parent_->left_ == _parent_node) {
                        this->RemoveHandleRedAndRed (_parent_node->parent_, 1);
                    }
                    else this->RemoveHandleRedAndRed (_parent_node->parent_, 0);
                }
            }
            else if (sibling->right_->color_ == RED) {
                this->RotateLeft (_parent_node);

                sibling->color_ = _parent_node->color_;
                _parent_node->color_ = BLACK;

                sibling->right_->color_ = BLACK;
            }
            else if (sibling->left_->color_ == RED) {
                this->RotateRight (sibling);

                sibling->parent_->color_ = BLACK;
                sibling->color_ = RED;

                this->RemoveHandleRedAndRed (_parent_node, 1);
            }
            else {
                // You should not arrive here.
                cout << "Something wrong in RedBlackTree::RemoveHandleRedAndRed function." << endl;
            }
        }
        // Target node is "Right" node.
        else {
            Node *sibling = _parent_node->left_;
            if (sibling->left_->color_ == BLACK && sibling->right_->color_ == BLACK) {
                if (_parent_node->color_ == RED) {
                    _parent_node->color_ = BLACK;
                    sibling->color_ = RED;
                }
                
                else {
                    sibling->color_ = RED;

                    if (_parent_node->parent_->left_ == _parent_node) {
                        this->RemoveHandleRedAndRed (_parent_node->parent_, 1);
                    }
                    else this->RemoveHandleRedAndRed (_parent_node->parent_, 0);
                }
            }
            else if (sibling->left_->color_ == RED) {
                this->RotateRight (_parent_node);

                sibling->color_ = _parent_node->color_;
                _parent_node->color_ = BLACK;

                sibling->left_->color_ = RED;
            }
            else if (sibling->right_->color_ == RED) {
                this->RotateLeft (sibling);

                sibling->parent_->color_ = BLACK;
                sibling->color_ = RED;

                this->RemoveHandleRedAndRed (_parent_node, 0);
            }
            else {
                // You should not arrive here.
                cout << "Something wrong in RedBlackTree::RemoveHandleRedAndRed function." << endl;
            }
        }
    }
    // Sibling is "RED".
    else {
        if (_parent_node->left_->color_ == RED) {
            this->RotateRight (_parent_node);

            _parent_node->color_ = RED;
            _parent_node->parent_->color_ = BLACK;
        }
        else if (_parent_node->right_->color_ == RED) {
            this->RotateLeft (_parent_node);

            _parent_node->color_ = RED;
            _parent_node->parent_->color_ = BLACK;
        }
        else {
            // You should not arrive here.
            cout << "Something wrong in RedBlackTree::RemoveHandleRedAndRed function." << endl;
        }
    }
}