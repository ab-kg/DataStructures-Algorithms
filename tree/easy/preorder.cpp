// Pre-order Traversal 
// Root Left Right 

// TC = O(N)
// SC = O(N)
#include <iostream>
using namespace std; 


struct Node 
{
    int data = 5 ;
    Node* left   ; 
    Node* right  ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};


void preorder(Node* root )
{
    if(root == NULL) return ;
    
    cout << root->data << endl ;
    preorder(root->left);
    preorder(root->right);

}


int main()
{
    Node* one = new Node(1);
    one->left = new Node(2);
    one->left->right = new Node(3);
    one->left->left = new Node(4);
    one->right = new Node(6);
    preorder(one);
}


