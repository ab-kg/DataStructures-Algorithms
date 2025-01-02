#include <iostream>
#include <vector>

class Node{
    public:
        int data ;
        Node* next ;
    public:
    // constructor
        Node(int data1 , Node* next1)
        {
            data = data1 ;
            next = next1 ;
        }
        Node(int data1)
        {
            data = data1 ;
            next = nullptr ;
            
            
        }
};

void PrintAll(Node* head)
{
    while(head != NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next ;
    }
}

// Function to insert a new node at the head of linked list 
Node* insertHead(Node *head , int value)
{
    Node *temp = new Node(value , head);
    return temp ;
}

// deleting the last node
Node* deleteLastNode(Node *head)
{      
    // If the list is empty or has only one node , return NULL 
    if( head == NULL || head->next == NULL)
    {
        return NULL;
    }
    // Initialize a temp pointer to traverse the list
    Node* temp = head ;

    while(temp->next != nullptr)
    {
        temp  = temp->next;
    }
    delete  temp ;
    return head ;
}


Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}

int PrintLen(Node *head)
{
    int count = 0 ;
    while(head != nullptr)
    {
        count++ ;
        head = head->next ;
    }
    return count ;
}

int lengthOfLinkedList(Node*head)
{
    Node *temp = head ;
    int cnt = 0 ;
    // Traverse the linked list and count nodes
    while(temp != NULL)
    {
        temp = temp->next ;
        cnt++;
    }
    return cnt;
}

// Search an element in a linked list
bool findElement(Node *head , int value )
{
    Node *temp = head ;
    while(temp != nullptr)
    {
        if(temp->data == value) return true ;
        
        temp = temp->next ;
    }
    return false ;
}


int main()
{
    std::vector<int> arr = { 1 , 2 , 3 , 4};      

    int val = 100 ;

    Node *head = new Node(arr[0]);
    // here a node is created 


    head->next = new Node(arr[1]);
    head->next->next  = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(34);
    // head = insertHead( head , val);
    // PrintAll(head);
    // head = deleteTail(head);
    // PrintAll(head);
    // std::cout << PrintLen(head) <<  std::endl;

    std::cout << findElement(head , 34) << std::endl;

    std::cin.get();
}


//  z -> y -> x 
