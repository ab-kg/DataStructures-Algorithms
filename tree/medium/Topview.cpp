#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

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
    vector<int> TopView(Node* root )
    {   
        vector<int> ans; 
        if(root == NULL) return ans;
        map<int , int> mpp; 
        queue<pair<Node* , int> > nodesQue ; 
        nodesQue.push( { root , 0});

        while(!nodesQue.empty())
        {
            auto p  = nodesQue.front();
            nodesQue.pop();
            int verticalLine = p.second ; 
            Node* node = p.first ; 
            if(mpp.find(verticalLine) ==  mpp.end()) mpp[verticalLine] = node->data ;

            if(node->left) nodesQue.push({node->left , verticalLine -1 });
            if(node->right) nodesQue.push({node->right , verticalLine + 1});
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
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

    Solution sol ; 
    vector<int> answer = sol.TopView(root);
    for(auto it : answer)
    {
        cout << it << endl;
    }
    return 0 ;
}
