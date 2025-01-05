// doubly linked list 
// Linked lists are linear data structures consisting of nodes , each containing data and a reference to the next node .
// doubly linked list has two pointers and hence the traversal is in both the direction.

#include <iostream>
#include <vector>

// Singly Linked List 
class Node1{
    public:
        int data ;
        Node1 *next ;

        Node1(int data1 , Node1* next1)
        {
            data = data1 ;
            next = next1 ;
        }

        Node1(int data1)
        {
            data = data1;
            next = nullptr ;
        }
};

// Doubly Linked List

class Node{
    public:
        int data ;
        Node* next ;
        Node* back ;

    Node(int data1 , Node* next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1 ;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr ;
        back = nullptr ;
    }
};

Node *deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL ;
    }
    Node* prev = head ;
    head = head->next ;
    head->back = nullptr ;
    prev->next = nullptr ;
    delete prev ;
    return head ;
}


Node* convertArr2DLL(std::vector<int> &arr)
{
    Node* head = Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ;i < arr.size() ; ++i)
    {
        Node* temp = Node(arr[i] ,nullptr , prev) ;
        prev->next = temp;
        prev = temp;
    }
    return head;
}


void print(Node* head)
{
    while(head != NULL)
    {
        std::cout << head->data <<" ";
        head = head->next ;
    }
    std::cout << "\n";
}

// -------------------------
// delete -> head 
//           tail
//           kth 
//           node 

Node* deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL ;
    }

    Node* prev = head;
    head = head->next ;

    head->back = nullptr ;
    prev->next = nullptr ;

    delete prev ;
    return head ;
}

// Node* deleteTail(Node* head)
// {   
//     Node *tail ;
//     while(tail->next != NULL)
//     {
//         tail = tail->next ;
//     }
//     Node *prev = tail->back ;
//     prev->next = nullptr ;
//     tail->back = nullptr ;
//     delete tail ;
// }

Node* deleteTail(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL ;
    }
    Node* tail = head ;
    while(tail->next != NULL)
    {
        tail = tail->next ;
    }
    Node* newTail = tail->back ;
    newTail->next = nullptr ;
    tail->back = nullptr ;

    delete tail ;
    return head ;
}


Node* kthElement(Node* head , int k )
{
    int count = 0 ;
    Node *temp = head;
    // this block of code takes the pointer temp to the kth element of the thing . 
    while(temp != nullptr)
    {   
        count++;
        if(count == k) break ;
        temp = temp->next ;
    }

    Node *prev = temp->back ;
    Node *front = temp->next ;
    
    if(prev == nullptr && front == nullptr) return nullptr ;
    else if(prev == nullptr) {  deleteHead(head); return head; }
    else if(front == nullptr){  deleteTail(head) ; return head; }
    else {
        prev->next = front ;
        front->back = prev ;
        temp->next = nullptr ;
        temp->back = nullptr ;
        delete temp ;
        return head ;
    }
    return head ; 
}


void deleteNode(Node* temp)
{
    Node* prev  = temp->back ;
    Node* front = temp->next ;

    if(front == NULL){
        prev->next = nullptr ;
        temp->back = nullptr ;
        free(temp);
        return ;
    }
    prev->next = front ;
    front->back = prev ;

    temp->next = temp->back = nullptr ;
    free(temp);
}

// --------------------
// insert at head
// insert after head 
// insert after kth element 
// insert befor tail 

Node* insertBeforeHead(Node* head , int value )
{
    Node* newHead = new Node(value , head , nullptr)   ;
    head->back = newHead ;
    return newHead ;
}

Node* insertAfterHead(Node* head , int value )
{
    Node* newnode = new Node(value , nullptr , head);
    newnode->next = head->next ;
    head->next = newnode ;
    return head;
}

Node* AfterkthElementInsert(Node* head , int k , int value)
{
    Node* temp = head ;
    int cnt = 0 ;
    while(temp != NULL)
    {   
        cnt++ ;
        if( cnt == k ) break ;
        temp = temp->next ;
    }

    Node* prev = temp->back ;
    Node* front = temp->next;

    Node* newnode = new Node(value , nullptr , temp);
    newnode->next = temp->next ;
    temp->next = newnode;
    return head;
}

Node* insertAfterTail(Node* head , int value)
{
    Node *temp = head;
    while( temp->next != NULL)
    {
        temp = temp->next ;
    }

    Node *newnode = new Node(value  , nullptr , temp);
    temp->next = newnode ;
    return head ;
}

// inserting before given node 
void insertBeforeNode(Node* node , int val)
{
    Node* prev = node->back ;
    Node* newnode = new Node(val , node , prev);
    prev->next = newnode ;
    node->back = newnode ;
}


int main()
{
    std::vector<int> arrary = { 12  , 1  , 2 , 3 , 4};
    Node* head = convertArr2DLL(arrary);
    // print(head);
    // head = deleteHead(head);
    // print(head);
    // head = deleteTail(head);
    // print(head);
    // head = kthElement(head  , 0);
    // print(head);

    head = insertBeforeHead(head , 1000);
    print(head);

    head = insertAfterHead(head , 999);
    print(head);

    head = AfterkthElementInsert(head , 1 , 5555);
    print(head);

    head = insertAfterTail(head , 24);
    print(head);

    return 0 ;
}
