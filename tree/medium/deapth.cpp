// Deapth of a binary tree

// How can we find out maximum deapth of binary tree , height of binary tree
// we need to traverse and keep a maxlength variable to check everytime we reach the null

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 

int maxDepth(Node* root){
    if(root == NULL) return 0 ;

    int lh = maxDepth(root->left) ;
    int rh = maxdepth(root->right);

    return 1 + max(lh , rh);
}

