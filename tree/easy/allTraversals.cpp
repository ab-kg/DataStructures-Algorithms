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


vector<int> preInPostTraversal(Node* root)
{
    stack<pair<Node* , int>> st ;
    st.push({root , 1});
    vector<int> pre , in , post ;
    if(root == NULL) return ;
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left  != NULL){
                st.push({it.first->left , 1});
            }
        }
        else if(it.second == 2){
            in.push_back(it.first->right , 1);
            it.second++;
            st.push(it);

            if(it.first->right != NULL)
            {
                st.push({it.first=>right , 1});
            }
            
        }
        else {
            post.push_back(it.first->data);
        }
    }

}
