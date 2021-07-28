// main.cpp

#include "RedBlackTree.hpp"
#include <iostream>

using namespace std;

int main (void) {

    RedBlackTree rbt_;
    Node *temp_node;

    int cmd, param;

    while (true) {
        cmd = 0;
        param = 0;
        // buffer [10] = {0, };

        
        cout << "(1) Create a node, (2) Remove a node, (3) Search a node" << endl;
        cout << "(4) Display Tree, (5) Quit." << endl;
        cout << "Enter command number : ";
        cin >> cmd;

        if (cmd < 1 || cmd > 5) {
            cout << "Invalid command number." << endl;
            continue;
        }
        else if (cmd == 4) {
            rbt_.PrintTree ();
            continue;
        }
        else if (cmd == 5) break;

        cout << "Enter parameter (1~200) : ";
        cin >> param;

        if (param < 1 || param > 200) {
            cout << "Invalid  parameter " << param << "." << endl;
            continue;
        }

        switch (cmd) {
        case 1:
            rbt_.InsertNode (new Node (param));
            break;
        case 2:
            temp_node = rbt_.RemoveNode (param);

            if (temp_node == NULL) cout << "Not found node: " << param << "." << endl;
            else delete temp_node;
            break;
        case 3:
            temp_node = rbt_.SearchNode (param);

            if (temp_node == NULL) cout << "Not found node: " << param << "." << endl;
            else {
                if (temp_node->color_ == RED) cout << "Found node: " << temp_node->data_ << "(Color: Red)" << endl;
                else cout << "Found node: " << temp_node->data_ << "(Color: Black)" << endl;
            } 
            break;
        }
    }

    return 0;
}