// Here in this problem we are checking 

#include <iostream>
#include <stack>
#include <vector>
// #include <max> 


using namespace std;

struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


class Solution
{
public:
    bool isBalanced(Node* root)
    {
        if(root == NULL) return true ;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left ) && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }


    int getHeight(Node* root)
    {
        if(root == NULL)  return 0 ;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return max(leftHeight , rightHeight) + 1 ;
    }
    
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);

    Solution solution; 

    if(solution.isBalanced(root))
    {
        cout << "The tree is balanced " << endl;
    }else {
        cout << "The tree is not balanced" << endl;
    }

    return 0 ;
}



