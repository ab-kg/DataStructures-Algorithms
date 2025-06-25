// inserting a node in Binary Search Tree

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
    TreeNode* insertIntoBST(TreeNode* root , int val)
    {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root ;
        while(true)
        {
            if(curr->val <= val)
            {
                if(curr->right != NULL) curr = curr->right
                else 
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else {
                if(curr->left != NULL) curr = curr->left;
                else 
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root ;
    }
}