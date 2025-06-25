#include <iostream>
#include <algorithm>
#include <climits>
#include <stack> 

using namespace std;

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize
    // the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};




