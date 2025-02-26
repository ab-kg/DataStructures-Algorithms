#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution 
{
public:
    Node* lowestCommonAncestor(Node* root , Node* p , Node* q)
    {
        if(root == NULL || root == p || root == q){
            return root ;
        }

        Node* left = lowestCommonAncestor(root->left , p , q);
        Node* right = lowestCommonAncestor(root->right , p , q );

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }

    Node* lowestCommonAncestor2(Node* root , Node* p , Node* q)
    {
        if(root == NULL || root == p || root == q){
            return root;
        }
        Node* left = lowestCommonAncestor2(root->left , p , q);
        Node* right = lowestCommonAncestor2(root->right , p , q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else {
            return root;
        }
    }

    
};
