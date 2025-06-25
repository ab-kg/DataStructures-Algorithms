#include <iostream>
#include <algorithm>
#include <climits>
#include <stack> 

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTIterator 
{
private:
    stack<Node* > myStack;
public:
    BSTIterator(Node* root)
    {
        pushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        Node* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }

private:
    void pushAll(Node* node )
    {
        for(; node != nullptr ; myStack.push(node) , node = node->left );
    }
};
