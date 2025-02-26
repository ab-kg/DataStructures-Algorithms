#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution 
{
public:
    bool getPath(Node* root , vector<int>& arr , int x)
    {
        if(!root) return false;

        arr.push_back(root->val);
        if(root->val == x) return true ;

        if(getPath(root->left , arr , x) || getPath(root->right , arr , x)){
            return true ;
        }

        arr.pop_back();
        return false;
    }

    vector<int> solve(Node* A , int B)
    {
        vector<int> arr ; 
        if(A == NULL) return arr ;
        getPath(A , arr , B);
        return arr ;
    }

};


