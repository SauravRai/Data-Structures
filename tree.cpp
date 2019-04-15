//author: Saurav Rai
//Tree implementation using C++ language
#include<iostream>
#include<stdlib.h> //for atoi
#include<queue>

using namespace std;

struct Node
      {
       int data;
       Node *left;
       Node *right;
      };

 class Tree
      {
         public:
         Node *root = NULL;
         Tree()
            {
              cout<<"The Constructor is called"<<endl;   
            }
 
         int isEmpty()
            {        
              if(root == NULL)
                  return 1;
              else 
                 return 0;               
            }
        Node *newNode(int element)
           {
             Node *temp;
             temp = new Node();
             temp->data = element;
             temp->left =NULL; 
             temp->right =NULL;
             return temp;              
           }      
        Node *insert_node(Node *root,int element)
          {
            if(root ==NULL)
               return(newNode(element));
            else
              {
                if(element<root->data)
                 {
                   root->left = insert_node(root->left , element);               
                 }     
               else
                {
                   root->right = insert_node(root->right, element);
                }
             }
          }        
          
        void inorder_traversal(Node *root)
          {
            if(root == NULL) 
               return;
            inorder_traversal(root->left);
            cout<<root->data;                
            inorder_traversal(root->right);
          }
        void postorder_traversal(Node *root)
          {
            if(root == NULL) 
               return;
            inorder_traversal(root->left);
            inorder_traversal(root->right);
            cout<<root->data;                
          } 
        void preorder_traversal(Node *root)
          {
            if(root == NULL) 
               return;
            cout<<root->data;                
            inorder_traversal(root->left);
            inorder_traversal(root->right);
          }       
         

         void breadth_first_search(Node *root)
          {
           queue <Node* >q;
           Node *node;
           if(root==NULL)              
              {
                cout<<"The tree is empty";
                return; 
              }
           else
              {
                 q.push(root);
                 while(q.front()!=NULL)
                  {
                   node = q.front();
                   cout<<node->data;
                   q.pop();
                   if(node->left!=NULL)
                     {
                       q.push(node->left); 
                     } 
                   if(node->right != NULL)
                     {
                       q.push(node->right);
                     }                         
                  }               
              }          
            } 
      }; 


  int main(int argc, char **argv)
     {
      
      Tree tree; 
      int size , element;
      if(argc!= 1)
       {
        cout<<"Enter the correct argument: "<<endl;       
       }
      size = atoi(argv[1]);     
      for(int i=0;i<size;i++)
          {
           cout<<"Enter the elements: "<<endl;  
           cin>>element;
           tree.root = tree.insert_node(tree.root,element);
          }     
      
       cout<<"Inorder traversal is: "<<endl;
       tree.inorder_traversal(tree.root);       
       cout<<endl; 
       cout<<"preorder traversal is: "<<endl;
       tree.preorder_traversal(tree.root);       
       cout<<endl; 
       cout<<"postorder traversal is: "<<endl;
       tree.postorder_traversal(tree.root);       
       cout<<endl; 
       cout<<"breadth first traversal is: "<<endl;
       tree.breadth_first_search(tree.root);       
        
       cout<<endl; 
      return 0;

     } 































