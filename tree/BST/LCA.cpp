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
    // Iterative way 
    TreeNode* LCA(TreeNode* root , TreeNode* p , TreeNode* q)    
    {
        if(root == NULL) return nullptr ;
        TreeNode* curr = root ; 
        while(true)
        {
            if(root->val >  p->val && root->val > q->val)
            {
                curr = curr->left ;
            }else if(root ->val < p->val && root->val < q->val)
            {
                curr = curr->right ;
            }else
            {
                return curr ;
                break;
            }
        }
        return nullptr ;
    }

    // Recursive Way 
    TreeNode* LCA(TreeNode* root , TreeNode* p , TreeNode* q)
    {
        if(root == nullptr) return nullptr ;
        int curr = root->val ;
        if(curr > p->val && curr > q->val)
        {
            return LCA(root->left , p , q );
        }
        if(curr < p->val && curr < q->val)
        {
            return LCA(root->right , p , q ) ;
        }
        return root ;
    }
};