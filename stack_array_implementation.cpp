//author: Saurav Rai
//Array implementstion of Stack using C++ language 
//pop, push, top/peek and isEmpty
#include<iostream>
using namespace std;

class Stack{
          int top;
          public:
            int arr[100];
            //member functions
           Stack() { top =-1;} //empty constructor
           bool push(int x);
           int pop();
           bool isEmpty();                       
           int top_display();
           };

  bool Stack::push(int a)
     {
        if(top>=100)
           {
            cout<<"Stack overflow"<<endl;
            return false;
           }
        else
           { 
            arr[++top]=a;} 
            cout<<"The element is pushed on the stack"<<a<<endl;
            return true;
     } 

  int Stack::pop()
    {
      if(top < 0)
        {
          cout<<"Stack underflow"<<endl;
        }
      else
        {
         int a = arr[top--];
         cout<<"The pop element is"<<a<<endl;
         return a;
       }

    }

  bool Stack::isEmpty()
    {
     return(top<0); //return true is it happens     
    }

   int Stack::top_display()
      { 
        cout<<"The top element in the stack is"<<arr[top]<<endl;    
      }
  int main()
     {
      class Stack s;
      s.push(2);  
      s.push(4);  
      s.push(5);  
      s.push(6);  
      s.push(7);  
      s.push(8);  
      s.pop();  
      s.pop();  
      s.top_display();  
    return 0;
     }
