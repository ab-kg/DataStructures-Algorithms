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


// BRUTE FORCE APPROACH 

class Solution 
{
public:
    vector<int> rightSideView(Node* root)
    {
        vector<int> res ;
        vector<vector<int> levelTraversal = levelOrder(root);

        for(auto level : levelTraversal )
        {
            res.push_back(level.back());
        }

        return res ; 
    }

    vector<int> leftSideView(Node* root)
    {
        vector<int> res ; 
        vector<vector<int>> levelTraversal = levelOrder(root);

        for(auto level : levelTraversal)
        {
            res.push_back(level.front());
        }

        return res; 
    }


private:
    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>> answer ; 

        if(!root){
            return ans;
        }

        queue<Node*> q ; 
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level ; 

            for(int i =0 ; i < size ; i++)
            {
                Node* top = q.front();
                q.pop();

                level.push_back(top->data);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            answer.push_back(level);
        }

        return answer;
    }

}


// OPTIMAL SOLUTION 


class BetterSolution
{
public:
    vector<int> rightSideView(Node* root)
    {
        vector<int> res ; 
        recursionRight(root , 0 , res);
        return res; 
    }

    vector<int> leftSideView(Node* root)
    {
        vector<int> res ;
        recursionLeft(root , 0 , res);
        return res ;
    }

private:
    void recursionLeft(Node* root , int level , vector<int>& res){
        if(root === NULL) return ;

        if(res.size() == level)
        {
            res.push_back(root->data);
            recursionLeft(root->left , level + 1 , res);
            recursionLeft(root->right , level + 1 , res );
        }
    }

    void recursionRight(Node* root , int level , vector<int>& res)
    {
        if(root == NULL) return ;

        if(res.size() == level)
        {
            res.push_back(root->data);
            
            recursionRight(root->right , level+1 , res);
            recursionRight(root->left , level + 1 , res);
        }
    }


}
