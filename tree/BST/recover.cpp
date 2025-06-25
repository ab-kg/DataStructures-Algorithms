#include <iostream>
#include <algorithm>
#include <climits>
#include <stack> 

using namespace std;

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize
    // the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    TreeNode* first ;
    TreeNode* prev ;
    TreeNode* middle ;
    TreeNode* last ;
private:
    void inorder(TreeNode* root){
        if(root == NULL) return ;

        inorder(root->left);

        if(prev != NULL && (root->val < prev->val) )
        {
            if(first == NULL)
            {
                first = prev ;
                middle = root ;
            }
            else
            {
                last = root;
            }
        }

        prev = root ;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root){
        first = middle = last = NULL ;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last ) swap(first->val , last->val);
        else if(first && middle) swap(first->val , middle->val);
    }    
}
