// Post-Order
// Left Right Root

#include <iostream>
using namespace std; 


struct Node 
{
    int data = 5 ;
    Node* left   ; 
    Node* right  ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 

void postorder(Node* root)
{
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

int main()
{
    Node* one = new Node(1);
    one->left = new Node(2);
    one->left->right = new Node(3);
    one->left->left = new Node(4);
    one->right = new Node(6);
    postorder(one);
}
