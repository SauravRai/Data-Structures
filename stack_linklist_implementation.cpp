//author: Saurav Rai
//Implementation of Stack Data Structure using linked lists
#include<iostream>
#include<stdlib.h>
#include<string>


using namespace std;

struct Node
   {
     int data;
     Node *next;  
   };

class Stack
    {
     private:
       Node * head;
     public:
       Stack() //empty constructor 
         {
          head = new Node(); 
          head->next =NULL;           
         } 
       int isEmpty()
         {
           if(head->next ==NULL)
              return 1;
           else 
              return 0;  
         }

       void push(int x)
         {
          Node * temp;
          temp = new Node();
          temp->data =x;
          temp->next = head->next;
          head->next = temp;  
         }

       int pop()
         {
           int a;
           if(!isEmpty()) // it is a function so need to use it properly
            {
              Node *temp;
              temp=head->next;  
              head->next = temp->next;
              a = temp->data;
              cout<<"The popped element is "<<temp->data<<endl;
              free(temp);
              return a;
           }
         } 
       
       void display()
         {
            Node *temp;
            temp =head->next;
            while(temp!=NULL)
               {
                 cout<<"The elements in the stack : "<<temp->data<<endl;      
                 temp = temp->next; 
               }
         }

       int top()
          { 
           if(!isEmpty())
             {
              int a;
              Node *temp;
              temp = head->next;  
              a = temp->data;
              return a;
             }   
          }
    };


  int main()
     {
       class Stack s;
       int x,y,z,w;
       int a;
       cout<<"Enter the elements in the stack: "<<endl; 
       cin>>x;     
       s.push(x);       
       cout<<"Enter the elements in the stack: "<<endl; 
       cin>>y;     
       s.push(y);       
       cout<<"Enter the elements in the stack: "<<endl; 
       cin>>z;     
       s.push(z);       
       cout<<"Enter the elements in the stack: "<<endl; 
       cin>>w;     
       s.push(w);       
       s.pop();
       a = s.top();  
       cout<<"The top element in the stack is: "<<a<<endl;
       s.display(); 
       return 0;
     }
