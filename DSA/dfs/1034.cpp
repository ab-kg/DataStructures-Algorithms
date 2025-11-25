#include <chrono>
#include <vector>
#include <iostream>

using namespace std;
using namespace std::chrono;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxdiff = INT_MIN;

    void dfs(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        vec.push_back(root->val);
        if (root->left) {
            for (auto& it : vec) {
                maxdiff = max(maxdiff, abs(it - root->left->val));
            }
            dfs(root->left, vec);
        }
        if (root->right) {
            for (auto it : vec) {
                maxdiff = max(maxdiff, abs(it - root->right->val));
            }
            dfs(root->right, vec);
        }
        vec.pop_back();
    }

    int dfs1(TreeNode* root, int mn, int mx) {
        if (!root) return mx - mn;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        int left = dfs1(root->left, mn, mx);
        int right = dfs1(root->right, mn, mx);
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs1(root, root->val, root->val);
    }
};

// Utility function to create test tree
TreeNode* buildTestTree1() {
    // Example: [8,3,10,1,6,null,14,null,null,4,7,13]
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    TreeNode* temp = root; 

    for (int i = 0; i < 100; i++)
    {
        root->left = new TreeNode(i);
        root = root->left; 
    }


    return temp;
}

TreeNode* buildTestTree2() {
    // Example: [1,null,2,null,0,3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(0);
    root->right->right->left = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    vector<TreeNode*> tests;
    tests.push_back(buildTestTree1());
    tests.push_back(buildTestTree2());

    for (int i = 0; i < tests.size(); i++) {
        auto start = high_resolution_clock::now();

        int ans = sol.maxAncestorDiff(tests[i]);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Test Case " << i + 1 << " -> Max Ancestor Difference = "
            << ans << " (Time taken: "
            << duration.count() << " nano seconds)" << endl;
    }

    cin.get();
    return 0;
}
