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
    TreeNode* bstFromPreorder(vector<int>& A)
    {
        int i = 0 ;
        return build(A , i , INT_MAX);
    }

    TreeNode* build(vector<int>&A , int& i , int bound)
    {
        if(i == A.size() || A[i] > bound) return NULL ;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A , i  , root->val);
        root->right = build(A , i , bound);
        return root ;
    }
}

