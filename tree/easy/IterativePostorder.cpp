// Post order
// left Right Root 

// Using two stacks

struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


vector<int> postOrderTraversal(Node* node)
{
    vector<int> postorder ; 
    if( root = NULL ) return postorder ;
    stack<Node*> st1 ;
    stack<Node*> st2 ;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL){
            st1.push(root->left);
        }
        if(root->right != NULL){
            st1.push(root->left);
        }
    }
    while(!st2.empty())
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder ;
}

