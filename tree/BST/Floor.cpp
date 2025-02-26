// Finding a Floor in a BST 

// key  = 7 
// Floor <= key 



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

    int Floor(Node* root , int key)
    {
        int floor = -1 ;
        while(root)
        {
            if(root->data == key ) {
                floor = root->data ;
                return floor ;
            }
            if(key > root->data){
                floor = root->data;
                root = root->right;
            }else{
                root = root->left ;
            }
        }
    }

};