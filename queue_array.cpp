//Author: Saurav Rai
//Implementation of queue operation using array in C++ 
#include<iostream>

using namespace std;
#define SIZE 5

class Queue
    {
     private:
      int items[SIZE] , rear , front;
     public:
      Queue()      
         {
          front = -1; 
          rear = -1;
         }
      bool isFull()
        {
         if(front == 0 && rear == SIZE -1)
           {
             return true;
           }
        else
            return false;      
        }
      bool isEmpty()
        {
          if(front ==-1)
            return true;
         else 
            return false;
        }  
        void enque(int x)
           {
            if(isFull())
             {
               cout<<"The queue is full:"<<endl;
             }
            else
               { if(front ==-1) {front = 0;}
                 rear++;
                 items[rear] = x;
                 cout<<"The inserted element is: "<<x<<endl;   
               }      
           }
         void deQueue()
           {   
             int element;
             if(isEmpty())
               {
                 cout<<"The queue is empty"<<endl;
               }
              //so it is not an empty queue 
               element = items[rear];
               if(front >= rear)
                  {
                    front  = -1;
                    rear = -1;             
                  }
               else
                 {
                  front++;
                 }                
               cout<<"The element to be deleted is: "<<element<<endl;
           }

         void display()
           {
            int i;
            if(isEmpty())
              {
               cout<<"The quueue is empty"<<endl;   
              }
            else
               { cout<<"The front element is: "<<items[front]<<endl; 
                 for(i = front;i<rear;i++)
                 {
                   cout<<"The elements of the queue is: "<<items[i]<<endl;    
                 }
                cout<<"The rear element is: "<<items[rear]<<endl; 
              }                
           } 
    };

 int main()
  {
    Queue queue;
    queue.deQueue();  
    queue.enque(2); 
    queue.enque(3); 
    queue.enque(4); 
    queue.enque(5); 
    queue.enque(6); 
    //cant be added coz queue is full
    queue.enque(7); 
    queue.display();
   return 0;
  }
  
   
