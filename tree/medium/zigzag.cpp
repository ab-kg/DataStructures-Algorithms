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
public:
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        vector<vector<int>> result ; 
        if(root == NULL){
            return result;
        }

        queue<Node*> nodesQue ; 
        nodesQue.push(root);

        bool leftToRight = true ;

        while(!nodesQue.empty())
        {
            int size = nodesQue.size();
            vector<int> row(size) ; 
            
            for(int i = 0 ; i < size ; i++)
            {
                Node* node = nodesQue.front();
                nodesQue.pop();

                int index = leftToRight ? i : (size - i - 1) ; 
                row[index] = node->data; 

                if(node->left){ 
                    nodesQue.push(node->left);
                }
                if(node->right) {
                    nodesQue.push(node->right);
                }
            }

            leftToRight = !leftToRight ; 
            result.push_back(row);
        }

        return result ; 
    }
};


void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution ;

    vector<vector<int>> result = solution.ZigZagLevelOrder(root);
    printResult(result);

    return 0 ;
}
