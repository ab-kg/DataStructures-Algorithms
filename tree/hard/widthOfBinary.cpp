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


class Solution {
public:
    int widthOfBinary(Node* root)
    {
        if(!root) return 0 ;
        int ans = 0  ; 
        queue<pair<Node* , int>> que ;
        que.push({root , 0});

        while(!que.empty())
        {
            int size = que.size();
            int mmin = que.front().second;

            
        }
    }
}