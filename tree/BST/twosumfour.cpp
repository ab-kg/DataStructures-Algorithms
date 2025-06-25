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
    stack<TreeNode*> myStack ;
    bool reverse = true ;
public:
    BSTIterator(TreeNode* root , bool isReverse)
    {
        reverse = isReverse ;
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }

    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmp->right);
        else pushAll(pushAll(tmp->left));
        return tmpNode->data;
    }

private:
    void pushAll(TreeNode* node)
    {
        for(; node != NULL ; ){
            myStack.push(node);
            if(reverse == true){
                node = node->right ;
            } else {
                node = node->left ;
            }
        }
    }
};


class Solution
{
public:
    bool findTarget(TreeNode* root , int k )
    {
        if(!root) return false ;
        BSTIterator l(root , false);
        BSTIterator r(root , true);

        int i = l.next();
        int j = r.next();

        while(i < j )
        {
            if(i + j == k) return true ;
            else if(i + j < k )  i = l.next();
            else j = r.next();
        }
        return false;
    }
}

