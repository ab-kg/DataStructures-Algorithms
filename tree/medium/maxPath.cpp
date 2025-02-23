// Maximum Sum Path in Binary Tree 
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
    int maxPathSum(Node* root)
    {
        int maxi = INT_MIN ; 
        maxPathDown(root , maxi);
        return maxi ;
    }

    int maxPathDown(Node* root , int &maxi)
    {
        if(root == NULL) return 0 ;

        int lh = max(0 , maxPathDown(root->left , maxi));
        int rh = max(0 , maxPathDown(root->right , maxi));
        maxi = max(maxi , lh + rh + root->data);
        return max(lh , rh) + node->val ; 
    }


};


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution ; 
    int ans = solution.maxPathSum(root);
    cout << ans << endl;
    return ans;
}