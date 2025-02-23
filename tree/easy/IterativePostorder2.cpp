// Post order
// left Right Root 

// Using one stack  

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct Node 
{
    int data = 5  ;
    Node* left    ;  
    Node* right   ;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
}; 


vector<int> postOrderTraversal(Node* root)
{
    vector<int> result ;
    if(root == NULL) return  result ;

    stack<Node*> st   ;
    Node* curr = root ;
    Node* prev = NULL ; 

    while(curr || !st.empty())
    {
        if(curr){
            st.push(curr)     ;
            curr = curr->left ;
        }
        else {
            Node* node = st.top() ;

            if(node->right && node->right != prev )
            {
                curr = node->right ;
            } else {
                result.push_back(node->data);
                prev = node ; 
                st.pop()    ;
            }
        }
    }
    return result           ;
}












// Driver Code
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = postOrderTraversal(root);
    cout << "Postorder Traversal: ";
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}