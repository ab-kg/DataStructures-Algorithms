// IN this problem we are trying to find out if two given trees are identical or not 


#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Node structure for the binary tree
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
    bool isIdentical(Node* root1 , Node* root2)
    {
        if(root1 == NULL && root2 == NULL)
        {
            return true ;
        }
        if(root1 == NULL || root2 == NULL)
        {
            return false;
        }
        return ((root1->data == root2->data ) && (isIdentical(root1->left , root2->left)) && (isIdentical(root1->right , root2->right)));
        
    }
};



int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);


    Solution solution ;
    bool value = solution.isIdentical(root1 , root2);

    cout << value << endl;
    return 0 ;
}
