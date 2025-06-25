// Inorder
// Left Root Right 
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


vector<int> inOrderTraversal(Node* root)
{
    stack<Node* > st ;
    vector<int> inorder ;
    Node* node = root ;

    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left ;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node);
            node = node->right ;
        }
    }
    return inorder ;
}


vector<int> inorderTraversal2(Node* root)
{
    stack<int> st ;
    vector<int> inorder ; 
    Node* node = root ;

    while(true)
    {
        if(node != NULL)
        {   
            st.push(node);
            node = node->left ;
        }
        else 
        {
            Node* required = st.top();
            st.pop();
            inorder.push_back(required);
            node = node->right ;
        }
    }
    return inorder ;
}





int main()
{

    return 1 ;
}
