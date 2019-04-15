//@author: Saurav Rai 
//Linked list implementation in C++
//created on 10 March 2019
//Run the code using the command : g++ linklist.py

#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

//forward declaration

class Node
    {
     public:
     int data;
     Node * next;
    };

Node * insert_at_beg(Node*, int);
Node * insert_at_end(Node*,int);
Node * delete_element(Node*,int);
Node * insert_ascending_list(Node* ,int);
Node * merge(Node *, Node *, Node *);
int pos(Node *, int);

void display(Node *head)
  {
    Node *temp;
    temp = head;
   while(temp!= NULL)
       {
        cout<<temp->data;
        cout<<endl;
        temp = temp->next; 
      }
  }

int main()
  {
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    
    Node *head1, *head2 ,*head3;
    //allocate three nodes in the heap
    head = new Node();    
    first = new Node();    
    second = new Node();    //we have pointers to these blocks as head, first and second 
       
    head1 = new Node();    
    head2 = new Node();    
    head3 = new Node();    
   
    head1->data = 1;
    head2->data = 1;
    head3->data = 1;

    head->data = 1;
    head->next = first;
    
    first->data = 2;
    first->next = second;
   
    second->data = 3;
    second->next = NULL;
    int a,d;
    int option;
    int position;
    int n,m;
    int s = 0;    
    //to print all the elements in the list
    do{
          cout<<"Enter your choice in the following"<<endl;
          cout<<"1.Display elements"<<endl;
          cout<<"2.Insert at the begining"<<endl;
          cout<<"3.Insert at the end"<<endl;
          cout<<"4.Delete an element in the list"<<endl;
          cout<<"5.Insert an element ascending in the list"<<endl;
          cout<<"6. Find the position of the element in the list "<<endl;
          cout<<"7. Merge two lists "<<endl;
          cin>>a;
          switch(a)
         { 

         case 1:cout<<"The elements in the list are: "<<endl;
                cout<<"Sairam"<<endl;
                display(head);
                break;
 
         case 2:cout<<"Inserting at the begining of the list: "<<endl;
                cout<<"Enter the element you wish to put in the beg of the list"<<endl;
                cin>>d;
                head = insert_at_beg(head,d);
                cout<<"The list after inserting the element in the begining"<<endl;
                display(head);
                break;  

         case 3:cout<<"Inserting at the end of the list: "<<endl;
                cout<<"Enter the element you wish to put in the end of the list"<<endl;
                cin>>d;
                head = insert_at_end(head,d);
                cout<<"The list after inserting the element in the end"<<endl;
                display(head);
                break;  

         case 4:cout<<"Deleting an element in the list: "<<endl;
                cout<<"Enter the element you wish to delete in the list"<<endl;
                cin>>d;
                head = delete_element(head,d);
                cout<<"The list after deleting element in the list"<<endl;
                display(head);
                break;

         case 5:cout<<"Insert an element in the ascending list: "<<endl;
                cout<<"Enter the element you wish to insert in the list"<<endl;
                cin>>d;
                head = insert_ascending_list(head,d);
                cout<<"The list after inserting element in the list"<<endl;
                display(head);
                break;

         case 6:cout<<"Insert an element of whose you want to find the position: "<<endl;
                cin>>d;
                cout<<endl;
                if((position=pos(head,d)) == -1)
                   {
                    cout<<"The node does not exist"<<endl;
                   }
                else
                 {
                   cout<<"The position of the node is"<<position<<endl;
                 }
                break;

         case 7:cout<<"Merge two lists in list: "<<endl;
                cout<<"Enter the size of first linked list"<<endl;
                cin>>n;
                cout<<"Enter the elements of the first linked list:"<<endl;
                 while( s < n)
                {
                  cout<<" Enter your number: "<<endl;
                  cin>>d; 
                  head1=insert_at_end(head1,d);
                  s++;
                }
                cout<<endl;
                display(head1);
                cout<<endl; 
                cout<<"Enter the size of second linked list:"<<endl;
                cin>>m;
                cout<<"Enter the elements of the second linked list:"<<endl;
                for(s=0;s<m;s++)
                 {
                  cout<<" Enter your number: "<<endl;
                  cin>>d; 
                  head2=insert_at_end(head2,d);
                 }
                display(head2);
                cout<<"The union of the two linked list is: "<<endl;

                head3=merge(head1,head2,head3);
                display(head3);
                break;

   
         default: cout<<"Please enter the correct option"<<endl;
                 break;        
          } 
         cout<<"Enter 1 for continue and 0 for discontinue"<<endl; 
         cin>>option;
      }while(option);     
   return 0;
  }

 
 Node * insert_at_beg(Node *h,int d)
   {
    Node * p; //Node to be addded in the list 
    p = new Node();
    p->data = d; 
    if(h==NULL)     
      {
       return p;
      }
    else
     {
      p->next = h;
      return p;
     } 
   }

  Node * insert_at_end(Node *h,int d)
     {
       Node *p;
       Node *temp;
       temp = h; 
       p =new Node();
       p->data =d;
       if(h == NULL) //if there is no element in the list
          {
           h = p;
           //return h; 
          }
       else if(h->next == NULL)
         {
          h->next = p;
          //return h; //if there is only one element in the list
         }
       else 
         {
          while(temp->next != NULL)
            {
               temp = temp->next; //traverse for the final node
            }      
           temp->next = p;
           p->next =NULL;
         //return h; 
         }
       return h;
      }

  Node * delete_element(Node *h , int d)
   { 
    Node *cur , *prev;
    cur =h;

    if(h ==NULL)
      {
       cout<<"The list is empty"<<endl; 
      }
    else if(h->data == d)
       {
         cur = h;
         h = cur->next;
         free(cur);       
       }
    //traverse the list to find the element to be deleted
    
    while(cur->next != NULL)
       {
         if(cur->data == d)
           {
             prev->next = cur->next;
             free(cur);  
           }
         else
           {
             prev = cur;
             cur = cur->next;
           }        
       }       
     return h;
   }   
  
Node * insert_ascending_list(Node *h ,int d)
  {
    Node *p;
    p = new Node();
    p->next =NULL;
    p->data = d;

   //if the head is NULL that is head is not created till now
   if(h==NULL)
    {
      h = new Node();
      h->data =d;
      h->next = NULL;  
    }     
    if(d<h->data)
      {
       p->next = h;
       return p;        
      }
    
     Node *temp = NULL;
     temp = h;
   
     while(temp->next != NULL && temp->data<d)
         {
          temp = temp->next; 
         }
        cout<<"temp data in ascending list is: "<<temp->data<<endl;
        p->next = temp->next;
        temp->next = p;
     return h;    
 }

  int pos(Node * h , int d)
    {
     int pos =1;
     int found = 0; 
     Node *t = NULL; 
     t = h;
     if(h==NULL)
       {
        pos =-1; 
       } 
     else
        {
          while(t!=NULL)
           {	
             if(t->data==d)
              { 
                 found =1;
                 break;
              } 
             else
              {  
                pos++;
              }
            t = t->next;  
           }
           
        }
     if(found)
       return pos;
     else 
       return -1;
    }  

Node * merge(Node *h1 , Node *h2, Node *head3)
   {
     Node *t1= NULL;
     t1 = h1;
     Node *t2= NULL;
     t2 = h2;
     while(t1 != NULL && t2 != NULL)
      {
         if(t1->data<t2->data)
          {
            head3 = insert_at_end(head3,t1->data);
            t1=t1->next;
          }   
         else 
            {
             if(t2->data<t1->data)
              {
               head3 = insert_at_end(head3,t2->data);
               t2=t2->next;
              }
            
             else //the elements in the the two linked lists are equal
              {
                head3 = insert_at_end(head3,t1->data);
                t1=t1->next;
                t2=t2->next;
              }
           }//else loop ends here  
      } //while loop ends here
   
    //individual case
    if(t1==NULL)
      {
        while(t2!=NULL)
          {
           head3 = insert_at_end(head3,t2->data);
           t2 = t2->next;
          }
      }
     else 
         if(t2==NULL)
            { 
                while(t1!=NULL)
              {
                head3 = insert_at_end(head3,t1->data);
                t1 = t1->next;
              }
           }     
    return head3; 
   }












