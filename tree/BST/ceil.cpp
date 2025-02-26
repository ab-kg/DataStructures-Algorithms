// Finding a Ceiling in a BST 


#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data = 5 ;
    Node* left ;
    Node* right ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};


class Solution
{
public:
    int Ceil(Node* root , int key )
    {
        int ceil = -1 ;
        while(root){
            if(root->data == key){
                ceil = root->data ;
                return ceil ;
            }
            if(key > root->data)
            {
                root = root->right;
            }
            else {
                ceil = root->data ;
                root = root->left ;
            }
        }
        return ceil ;
    }
};