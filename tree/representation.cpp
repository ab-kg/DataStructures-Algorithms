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
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    return  0 ;
}


