#include<iostream.h>
#include<conio.h>
struct node
{
 int data;
 node *left;
 node *right;
}*root=NULL,*parent=NULL;
node* Insert(node *temp,int item)
{
 if(temp==NULL)
 {
  temp=new node;
  temp->data=item;
  temp->left=NULL;
  temp->right=NULL;
 }
 else if(item<temp->data)
 temp->left=Insert(temp->left,item);
 else
 temp->right=Insert(temp->right,item);
 return temp;
}
void inorder(node *temp)
{
 if(temp==NULL)
 return;
 inorder(temp->left);
 cout<<temp->data<<" ";
 inorder(temp->right);
}
node* Search(node *temp,int item)
{
 if(temp==NULL||temp->data==item)
 return temp;
 else if(item<temp->data)
 temp=Search(temp->left,item);
 else
 temp=Search(temp->right,item);
 return temp;
}
node* FindSucc(node *ptr)
{
 node* succptr;
 succptr=ptr->right;
 while(succptr->left!=NULL)
 succptr=succptr->left;
 return succptr;
}
node *SearchParent(node *temp,int item)
{
 if(temp==NULL||temp->data==item)
 return parent;
 else if(item<temp->data)
 {
  parent=temp;
  temp=SearchParent(temp->left,item);
 }
 else
 {
  parent=temp;
  temp=SearchParent(temp->right,item);
 }
 return temp;
}
node* Delete(node *temp,int item)
{
 node *ptr;
 ptr=Search(temp,item);
 parent=SearchParent(temp,item);
 if(ptr==NULL)
 cout<<"\nNot present!!!";
 else if(ptr->left==NULL&&ptr->right==NULL)
 {
  if(ptr==temp)
  temp=NULL;
  else
  {
   if(parent->right==ptr)
   parent->right=NULL;
   else
   parent->left=NULL;
  }
  delete ptr;
 }
 else if(ptr->left!=NULL&&ptr->right==NULL)
 {
  if(ptr==temp)
  temp=temp->left;
  else
  {
   if(parent->right==ptr)
   parent->right=ptr->left;
   else
   parent->left=ptr->left;
  }
  delete ptr;
 }
 else if(ptr->left==NULL&&ptr->right!=NULL)
 {
  if(ptr==temp)
  temp=temp->right;
  else
  {
   if(parent->right==ptr)
   parent->right=ptr->right;
   else
   parent->left=ptr->right;
  }
  delete ptr;
 }
 else if(ptr->left!=NULL&&ptr->right!=NULL)
 {
  node *succptr;
  succptr=FindSucc(ptr);
  ptr->data=succptr->data;
  succptr=Delete(succptr,succptr->data);
 }
 return temp;
}
void main()
{
 clrscr();
 int ch,value;
 char c;
 node *temp;
 cout<<"Enter value in first node: ";
 cin>>value;
 root=Insert(root,value);
 cout<<"Do you want to enter more nodes? y or n-";
 cin>>c;
 while(c=='y'||c=='Y')
 {
  cout<<"Enter value: ";
  cin>>value;
  root=Insert(root,value);
  cout<<"Do you want to enter more nodes? y or n-";
  cin>>c;
 }
 do
 {
  clrscr();
  cout<<"\nChoose: ";
  cout<<"\n1. Search a node";
  cout<<"\n2. Insert a node";
  cout<<"\n3. Delete a node";
  cin>>ch;
  if(ch==1)
  {
   cout<<"\nEnter the node u want to search for: ";
   cin>>value;
   temp=Search(root,value);
   if(temp==NULL)
   cout<<"\nNOT PRESENT!!!";
   else
   cout<<"\nFound!!!";
  }
  else if(ch==2)
  {
   cout<<"\nEnter the value u want to insert:";
   cin>>value;
   root=Insert(root,value);
   cout<<"\nInorder traversal of updated tree: ";
   inorder(root);
  }
  else if(ch==3)
  {
   cout<<"\nEnter the node to be deleted: ";
   cin>>value;
   root=Delete(root,value);
   cout<<"\nInorder traversal of updated tree: ";
   if(root==NULL)
   cout<<"\nEmpty tree!!!";
   else
   inorder(root);
  }
  else
  cout<<"\nWrong choice!!!";
  cout<<"\nDo you want to perform more??? y or n-";
  cin>>c;
 }while(c=='y'||c=='Y');
 getch();
}