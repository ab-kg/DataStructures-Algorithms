// Here we are checking if the given TREE is BST 

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


class  Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        return isValiddBST(root , INT_MIN , INT_MAX);
    }

    bool isValiddBST(TreeNode* root , long minVal , long maxVal )
    {
        if(root == NULL)  return true ;
        if(root->val >= maxVal || root->val <= minVal ) return false;
        return isValiddBST(root->left , minVal , root->val) && isValiddBST(root->right , root->val , maxVal);
    }
}

