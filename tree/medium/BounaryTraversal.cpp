// Boundary Traversal is a process of visiting boundary nodes in anticlockwise direction .


// Boundary Traversal has its own algorithm in place which is documneted in my DSA notebook for reference . 
// I think its better if i use pen and paper to think better typing on laptop is fine , i think i still need some more 
// time to be totally used to only write on laptop rather than anything . 

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

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
    bool isLeaf(Node* root)
    {
        if(root->left == nullptr && root->right == nullptr && root != nullptr )
        {
            return true ;
        }
        return false;
    }

    void addLeftBoundary(Node* root , vector<int>& res)
    {
        Node* curr = root->left ; 
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right ;
        }
    }

    void addRightBoundary(Node* root , vector<int>& res)
    {
        Node* curr = root->right ; 
        vector<int> temp ;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right ; 
            else curr = curr->left ; 
        }

        for(int i = temp.size()-1 ; i >= 0 ; i--){
            res.push_back(temp[i]);
        }

    }

    void addLeaves(Node* root , vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return ;
        }
        if(root->left) addLeaves(root->left , res);
        if(root->right) addLeaves(root->right , res ) ;
    }

public:
    vector<int> printBoundary(Node* root)
    {
        vector<int> res;
        if(!root) return res ; 
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root , res);
        addLeaves(root , res);
        addRightBoundary(root , res);
        return res ;
    }

};


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(5);
    root->left->left->left->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9) ; 
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    Solution solution ;

    vector<int> ans = solution.printBoundary(root);
    for(auto it : ans){
        cout << it << endl;
    }

    return 0 ;
}

