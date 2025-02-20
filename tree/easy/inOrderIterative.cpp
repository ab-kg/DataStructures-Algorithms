// Inorder
// Left Root Right 


struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


vector<int> inOrderTraversal(Node* root)
{
    stack<Node*> st ;
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



    // stack<Node*> st;
    // Node* node = root;
    // vector<int> inorder ;
    // while(true)
    // {
    //     if(node != NULL) {
    //         st.push(node);
    //         node =  node->left ;
    //     } else 
    //     {
    //         if(st.empty() == true) break;
    //         node = st.top();
    //         st.pop();
    //         inorder.push_back(node->data);
    //         node = node->right;
    //     }
    // }
    // return inorder ;