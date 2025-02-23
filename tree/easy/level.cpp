// Level Order Traversal
//         1
//     2       3
//   4   5   6   7

// --> 1 2 3 4 5 6 7 

// For doing level order traversal we use queue data structure
// we store the level elements in queue and push them into the level vector 
// and push the next level elements in the queue and things go on like that . 

// TC = O(N)
// SC = O(N)


#include <iostream>
using namespace std; 
#include <vector>
#include <queue>

struct Node 
{
    int data = 5 ;
    Node* left   ; 
    Node* right  ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> que ;
    que.push(root);
    while(!que.empty())
    {
        vector<int> level ;
        int size = que.size();
        for(int i = 0 ;i < size ; i++)
        {
            Node* node = que.front();
            que.pop();
            level.push_back(node->data);
            if(node->left != nullptr)
            {
                que.push(node->left);
            }
            if(node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}


//      1 
//   2     6 
// 4   3  

int main()
{
    Node* one = new Node(1);
    one->left = new Node(2);
    one->left->right = new Node(3);
    one->left->left = new Node(4);
    one->right = new Node(6);

    vector<vector<int>> ans = levelOrder(one);

    for(auto it : ans)
    {
        for(auto itt : it)
        {
            cout << itt << endl;
        }
    }

    return 0 ;
}

