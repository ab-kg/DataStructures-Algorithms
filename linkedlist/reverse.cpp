// In this program we are trying to reversing the linked list 


// Brute Force 
// Store data in linked list in Stack 
// And replace the values from the stack 
// LAST IN FIRST OUT --> principle of stack is helpful here 

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data ;
        Node *next ;
        Node *back ;
    
    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1 ;
        next = next1 ;
        back = back1 ;
    }

    Node(int data1)
    {
        data = data1 ;
        next = nullptr ;
        back = nullptr ;
    }

};

Node* convertArr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]) ;
    Node *prev = head ;

    for(int i = 1 ; i < arr.size() ; i++)
    {
        Node *temp = new Node(arr[i] , nullptr , prev);
        prev->next = temp ;
        prev = temp ;
    }
    return head ;
}

void print(Node *head)
{
    while(head != NULL)
    {
        std::cout <<  head->data << std::endl ;
        head = head->next ;
    }
}

// Reverse the DLL using stack 
Node* reverseDLL(Node* head)
{
    if(head==NULL || head->next == NULL){
        return head;
    }

    stack<int> st ;

    // Initialise the node pointer temp at head 
    Node *temp = head ;
    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reinitailse temp to head 
    temp = head ;

    // Second iteration of the DLL to replace the values 
    while(temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next ;
    }
    return head ;
}

// Reverse Doubly Linked List without Stack
Node *reverseDLL2(Node* head){ 
    if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return head; 
    }
    
    Node* prev = NULL ;
    
    Node* current = head ;

    while(current != NULL){
        prev = current->back ;
        current->back = current->next;
        current->next = prev ;
        current = current->back ;
    }

    return prev->back ;

}









int main()
{
    vector<int> arr = { 12 , 2  , 3  , 4 ,5  , 6};
    Node *head = convertArr2DLL(arr);
    std::cout << "double linked list initially\n" ;
    print(head);
    std::cout << "\n";
    std::cout << "DOuble linked list after reversing\n";

    head = reverseDLL(head);
    print(head);
    return 0 ;
}
