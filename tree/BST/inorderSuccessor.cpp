#include <iostream>
#include <algorithm>
#include <climits>

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


class Solution
{
public:
    TreeNode* inorderSuccessor(TreeNode* root , TreeNode* p )    
    {
        TreeNode* successor = NULL ;
        while(root != NULL)
        {
            if(p->val >= root->val)
            {
                root = root->right ;
            } else
            {
                successor = root ;
                root = root->left ;
            }
        }
        return successor ;
    }
}

