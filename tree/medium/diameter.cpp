// Diameter of tree
// Longest distance between any two nodes of that tree 

#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
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
    int diameter = 0 ;

    int calculateHeight(Node* root)
    {
        if(root == NULL ) return 0 ;

        int  leftHeight = calculateHeight(root->left);
        int  rightHeight = calculateHeight(root->right);

        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight , rightHeight);
    }

    int heightEfficiently(Node* root , diameter)
    {
        if(!root) return 0 ;

        int lh = heightEfficiently(root->left , diameter);
        int rh = heightEfficiently(root->right , diameter);
        diameter = max(diameter , lh + rh );
        return 1 + max(lh ,rh);
    }

    int diameterOfBinaryTree(Node* root)
    {
        int ans = calculateHeight(root);
        return ans;
    }

};


// TO  make the program more efficient we need to make sure that we are using postOrder traversal
// As it is the most efficient and we need not need to repeatedly calculate heights of left and right subtree unnecesarily 
