// Pre-order Traversal 
// Root Left Right 
#include <iostream>

struct Node 
{
    int data = 5 ;
    Node* left ; 
    Node* right  ;

    Node(int val)
    {
       Node data = val ;
       left = right = NULL ; 
    }

};


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    return  0 ;
}


