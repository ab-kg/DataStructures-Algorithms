// Preorder
// Root Left Right

// Not using Recursion but in a Iterative way .

// TC -> O(N)
// SC -> O(N)


#include <iostream>
#include <vector>
#include <stack> 

using namespace std; 

struct Node 
{
    int data = 5 ;
    Node* left   ; 
    Node* right  ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 

vector<int> preorderTraversal(Node* root)
{   
    vector<int> preorder;
    stack<Node*> st;
    if(root == NULL) return preorder ;
    st.push(root);

    while(!st.empty())
    {
        Node* node = st.top();
        st.pop();
        preorder.push_back(node->data);
        
        if(node->right != nullptr)
        {
            st.push(node->right);
        }

        if(node->left != nullptr)
        {
            st.push(node->left);
        }
    }

    return preorder ;
}


// Recursive way of implementing PREORDER => root - left - right 

void preOrder(Node* root ,    vector<int>& arr  )
{

    if(root == nullptr)  return  ;
    arr.push_back(root->data);
    preOrder(root->left , arr);
    preOrder(root->right ,arr);

}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    // vector<int> ans  = preorderTraversal(root);
    vector<int> ans; 

    preOrder(root , ans);

    for(auto it : ans)
    {
        cout << it << endl;
    }
    return 0 ;

}


