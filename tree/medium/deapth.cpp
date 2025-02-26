// Deapth of a binary tree

// How can we find out maximum deapth of binary tree , height of binary tree
// we need to traverse and keep a maxlength variable to check everytime we reach the null

#include <iostream>
#include <stack>
#include <vector>
// #include <max> 


using namespace std;

struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


int maxDepth(Node* root){
    if(root == NULL) return 0 ;

    int lh = maxDepth(root->left) ;
    int rh = maxDepth(root->right);

    return 1 + max(lh , rh);
}

vector<int> ans;

void preOrder(Node* root)
{
    if(root == NULL) return ;
    ans.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void printVector(vector<int>& ans)
{
    for(auto it : ans)
    {
        cout << it << endl;
    }
}

int main()
{
    Node* one = new Node(1);
    one->left = new Node(2);
    one->right = new Node(3);
    one->left->left = new Node(4);
    int anss = maxDepth(one);
    cout << anss << endl;

    preOrder(one);
    printVector(ans);

    return 0 ;

}