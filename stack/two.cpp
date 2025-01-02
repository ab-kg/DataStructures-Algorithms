// implementing Queue using Linked List

#include<bits/stdc++.h> 
using namespace std;

class QueueNode {
    public :
        int val ;
        QueueNode *next;
        QueueNode(int data){
            val = data ;
            next = nullptr;
        }
};

QueueNode *Front = nullptr , *Rare = nullptr ;

class Queue{
    public:
        int size = 0 ;
        bool Empty();
        void Enqueue(int value);
        void Dequeue();
        int Peek();
};

bool Queue :: Empty()
{
    return Front == nullptr ;
}

void Queue :: Enqueue(int value)
{
    QueueNode *Temp ;
    Temp = new QueueNode(value);
    if(Temp == nullptr)
        { cout << "Queue is full" << endl;
        exit(1);}
    else {
        if(Front == nullptr )
        {
            Front = Temp ;
            Rare  = Temp;
        }
        else{
            Rare->next = Temp ;
            Rare = Temp ;
        }
        cout << value << "Inserted into Queue " << endl;
        size++;
    }
}

void Queue :: Dequeue()
{
    if(Front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << Front->val << "Removed from queue" << endl;
        QueueNode *Temp = Front ;
        Front = Front->next;
        delete Temp ;
        size--;
    }
}


int Queue :: Peek()
{
    if(Empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else 
        return Front->val ;
}

