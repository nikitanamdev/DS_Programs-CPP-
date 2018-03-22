#include<iostream.h>
#include<conio.h>
struct node
{
 int data;
 node *left;
 node *right;
}*root=NULL;
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
void preorder(node *temp)
{
 if(temp==NULL)
 return;
 cout<<temp->data<<" ";
 preorder(temp->left);
 preorder(temp->right);
}
void inorder(node *temp)
{
 if(temp==NULL)
 return;
 inorder(temp->left);
 cout<<temp->data<<" ";
 inorder(temp->right);
}
void postorder(node *temp)
{
 if(temp==NULL)
 return;
 postorder(temp->left);
 postorder(temp->right);
 cout<<temp->data<<" ";
}
void main()
{
 clrscr();
 int ch,value;
 char c;
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
  cout<<"\n1. Preorder traversal of tree";
  cout<<"\n2. Inorder traversal of tree";
  cout<<"\n3. Postorder traversal of tree";
  cin>>ch;
  if(ch==1)
  {
   preorder(root);
   cout<<endl;
  }
  else if(ch==2)
  {
   inorder(root);
   cout<<endl;
  }
  else if(ch==3)
  {
   postorder(root);
   cout<<endl;
  }
  else
  cout<<"\nWrong choice!!!";
  cout<<"\nDo you want to perform more? y or n-";
  cin>>c;
 }while(c=='y'||c=='Y');
 getch();
}
