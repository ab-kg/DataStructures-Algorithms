// Here we are trying to delete the node which is present in the Binary Search Tree

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
    TreeNode* deleteNode(TreeNode* root , int key)
    {
        if(root == NULL)  return NULL ;
        if(root->val == key) return helper(root);
        TreeNode* dummy = root  ;
        while(root != NULL)
        {
            if(root->val > key)
            {
                if(root->left && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }else
                {
                    root = root->left ;
                }
            } else
            {
                if(root->right && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy ;
    }

    TreeNode* helper(TreeNode* root)
    {
        if(root->left == NULL)
        {
            return root->right ;
        }else if(root->right == NULL)
        {
            return root->left ;
        }
        TreeNode* rightChild = root->right ;
        TreeNode* lastRight = lastChild(root->left);
        lastRight->right = rightChild ;
        return root->left;
    }

    TreeNode* lastChild(TreeNode* root)
    {
        if(root->right == NULL)
        {
            return root ;
        }
        return lastChild(root->right);
    }
    
};