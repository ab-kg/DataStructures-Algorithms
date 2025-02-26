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
    Node* searchBST(Node* root , int val)
    {
        while(root != NULL && root->data != val){
            root = val < root->data ? root->left : root->right ;
        }
        return root ;
    }
};




