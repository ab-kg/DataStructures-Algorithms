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
    vector<vector<int>> findVertical(Node* root){
        map<int , map<int , multiset<int>> > nodes ; 

        queue<pair<Node*, pair<int , int> >> todo ; 
        todo.push({root , {0 , 0}});

        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            Node* node = p.first ; 
            int x = p.second.first , y = p.second.second ; 
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left , {x - 1 , y + 1 }});
            }
            if(node->right){
                todo.push({node->right , {x + 1 , y + 1 }});
            }
        }



        vector<vector<int>> answer ; 

        for(auto p : nodes){
            vector<int> col ; 
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin() , q.second.end());
            }
            answer.push_back(col);
        }

        return answer;
    }
}


