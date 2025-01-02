#include <iostream>
// #include <stack>
// #include <queue>
// stack holds a certain type of data type .

// stack LIFO
// queue FIFO

// push 
// pop 
// top 
// size 

// implementing stack using array 
// size has to be known 

#include <stack>
using namespace std;

class Stack {
    int top ;
    int size ;
    int *arr ;
    public :
        Stack(){
            top = -1 ;
            size = 1000;
            arr = new int[size];
        }

        void push(int x)
        {
            top++;
            arr[top] = x;
        }

        int pop(){
            int x = arr[top];
            top--;
            return x ;
        }

        int Top(){
            return arr[top];
        }

        int Size(){
            return top + 1;
        }      
};

int main1(){

    Stack s ;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << s.Top() << endl;
    cout << s.Size() << endl;
    cout << s.pop() << endl ;
    cout << s.Size() << endl ;
    cout << s.Top() << endl ;
    return 0 ;
}

// implementing queue using array 
// size has to be known 

// does that mean stack and Queue are stack allocated.

class Queue {
    int *arr ;
    int start , end , currSize , maxSize ;
    public:
    // constructor without maxSize 
        Queue(){
            arr = new int[16];
            start = -1 ;
            end = -1 ;
            currSize = 0 ;
            maxSize = 10 ;
        }

    // constructor with maxSize 
        Queue(int maxSize){
            (*this).maxSize = maxSize ;
            arr = new int[maxSize];
            start = -1 ;
            end = -1 ;
            currSize = 0 ;
        }

        void push(int newElement)      {
            if(currSize == maxSize) {
                cout << "FUll" << endl;
                exit(1);
            }

            if(end == -1 ){
                start = 0 ;
                end = 0;
                arr[start] = newElement ;
                cout << "the element is pushed" << endl;
                currSize++ ;
            }else{
                end = (end + 1 ) % maxSize ;
                arr[end] = newElement ;
                cout << "The element is pushed " << endl ;
                currSize++ ;
            }
        }

        int pop(){
            if( start == -1){
                cout << "Queue is empty"<< endl;
            }
            int popped = arr[start];
            if(currSize == 1){
                start = -1 ;
                end = -1 ;
            }else{
                start = (start +1) % maxSize ;
            }
            currSize--;
            return popped ;
        }

        int top(){
            if( start == -1){
                cout << "Queue is empty" << endl;
            }
            return arr[start];
        }

        int size(){
            return currSize ;
        }

};

int main2(){
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << q.top() << endl;
    cout << q.size() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.size() << endl ;
    return 0;
}

// implementing stack using Linked List 

struct stackNode {
    int data ;
    stackNode *next ;

    stackNode(int d){
        data = d ;
        next = NULL;
    }
};

struct Stackk {
    stackNode * top ;
    int size ;
    Stackk(){
        top = NULL ;
        size = 0 ;
    }

    void stackPush(int x ){
        stackNode *element = new stackNode(x);
        element-> next = top ;
        top = element ;
        cout << "Element pushed " << endl; 
        size++ ;
    }

    int stackPop(){
        if(top == NULL) return -1;
        int topData = top->data ;
        stackNode *temp = top;
        top = top->next ;
        delete temp;
        size--;
        return topData;
    }

    int stackSize(){
        return size;
    }

    bool stackIsEmpty(){
        return top == NULL;
    }

    int stackPeek(){
        if (top == NULL) return -1;
        return top->data ;
    }

    void printStack(){
        stackNode *current = top ;
        while(current != NULL){
            cout << current->data << " " ;
            current = current->next;
        }
    }
    
};

int main3(){
    Stackk s ;
    s.stackPush(10);
    s.stackPush(34);
    s.stackPush(99);

    cout << s.stackPop() << endl;
    cout << s.stackSize()  << endl;
    cout << s.stackPeek() << endl;
    s.printStack();

    return 0 ;
}

// hardcore developer 
