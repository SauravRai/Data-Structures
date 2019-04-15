//author: Saurav Rai
//Implementation of queue using linked list in C++
#include<iostream>

using namespace std;

struct Node
   {
     int data;
     Node *next; 
   };

class Queue
   {
    public:  
    Node *front , *rear;
    Queue() //constructor call for the empty queue
       {
         front = rear =NULL;
       } 
     void insert_ele(int );                         
     void delete_ele(); 
     void display(); 
     ~Queue();    
   };

void Queue::insert_ele(int element)
   {
     Node *temp  = new Node;
     if(temp ==NULL)
       {
         cout<<"Queue overlflow "<<endl;

       }
     temp->data = element;  
     temp->next = NULL;
     //for the front node
     if(front ==NULL)
       {
         front =  rear =temp;
       } 
     else
       {
         rear->next = temp;
         rear =temp;
       }
      cout<<element<<" has been inserted in the Queue successfully"<<endl;
   }

  void Queue::delete_ele()
    {
     if(front==NULL)
       cout<<"Queue underflow"<<endl; 
     cout<<"The element to be deleted is"<<front->data<<endl; 
     if(front == rear)  //there is only element
        front = rear =NULL;
     else
       {
        front = front->next; 
       } 
    } 

   void Queue::display()
      {
        if(front ==NULL)
          {
           cout<<"Under flow"<<endl;
          }
        Node *temp = front;
        while(temp)           
         {
          cout<<"The elements in the queue is: "<<temp->data<<endl;
          temp = temp->next;
         } 
       cout<<endl;
      }

  Queue ::~Queue()
   {
      while(front!=NULL)
       { 
         Node *temp = front;
         front = front->next;
         delete temp;
       }
     rear =NULL;    
   }

 int main()
   {
    Queue Q;
    Q.display(); 
    Q.insert_ele(10); 
    Q.insert_ele(20); 
    Q.insert_ele(30); 
    Q.insert_ele(40); 
    Q.insert_ele(50); 
    Q.insert_ele(60); 
  
    Q.display();

    Q.delete_ele(); 
    
    Q.display();
   return 0;
   }
