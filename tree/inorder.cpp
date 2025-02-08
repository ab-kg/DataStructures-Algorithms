// Inorder
// Left Root Right 

#include <iostream>
using namespace std; 


struct Node 
{
    int data = 5 ;
    Node* left   ; 
    Node* right  ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 

void inorder(Node* root)
{
    if(root == NULL) return ;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main()
{
    Node* one = new Node(1);
    one->left = new Node(2);
    one->left->right = new Node(3);
    one->left->left = new Node(4);
    one->right = new Node(6);
    inorder(one);
}


//      1 
//   2     6 
// 4   3  