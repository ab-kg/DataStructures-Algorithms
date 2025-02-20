// Preorder
// Root Left Right

// Not using Recursion but in a Iterative way .

// TC -> O(N)
// SC -> O(N)


#include <iostream>
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


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    vector<int> ans  = preorderTraversal(root);

    for(auto it : ans)
    {
        cout << it << endl;
    }

    return 0 ;

}


