#include<iostream.h>
#include<conio.h>
struct NODE
{
 int data;
 NODE *next;
 NODE *prev;
}*list;
void Traverse_DLL(NODE *list)
{
 NODE *temp;
 temp=list;
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->next;
 }
}
void Insert_after_DLL(NODE *list,int value,int key)
{
 NODE *temp,*temp1;
 temp=new NODE;
 temp->data=value;
 temp->prev=NULL;
 temp->next=NULL;
 temp1=list;
 while(temp1->data!=key&&temp1->next!=NULL)
 temp1=temp1->next;
 if(temp1->data==key)
 {
  temp->next=temp1->next;
  temp->prev=temp1;
  if(temp1->next!=NULL)
  temp1->next->prev=temp;
  temp1->next=temp;
 }
 else
 cout<<"Key not found\n";
}
void Insert_before_DLL(int value,int key)
{
 NODE *temp,*temp1;
 temp1=list;
 temp=new NODE;
 temp->data=value;
 temp->next=NULL;
 temp->prev=NULL;
 while(temp1->next!=NULL&&temp1->data!=key)
 temp1=temp1->next;
 if(temp1->data==key)
 {
  if(temp1==list)
  {
   temp->next=list;
   temp->prev=NULL;
   list->prev=temp;
   list=temp;
  }
  else
  {
   temp->next=temp1;
   temp1->prev->next=temp;
   temp->prev=temp1->prev;
   temp1->prev=temp;
  }
 }
 else
 cout<<"Key not found\n";
}
void Delete_DLL(int key)
{
 NODE *temp;
 temp=list;
 if(temp->data==key)
 {
  list=list->next;
  list->prev=NULL;
  delete temp;
 }
 else
 {
  while(temp->next!=NULL&&temp->data!=key)
  temp=temp->next;
  if(temp->data==key)
  {
   if(temp->next==NULL)
   temp->prev->next=NULL;
   else
   {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
   }
   delete temp;
  }
  else
  cout<<"Key not found\n";
 }
}
void main()
{
 int value,key,choice,inschoice;
 char c,c1;
 list=new NODE;
 cout<<"Enter value in first node";
 cin>>value;
 list->data=value;
 key=value;
 list->next=NULL;
 list->prev=NULL;
 cout<<"Do you want to make new node? y or n-";
 cin>>c;
 while(c=='y'||c=='Y')
 {
  cout<<"Enter value:";
  cin>>value;
  Insert_after_DLL(list,value,key);
  key=value;
  cout<<"Do you want more nodes? y or n-";
  cin>>c;
 }
 do
 {
  clrscr();
  cout<<"Select the operation: \n";
  cout<<"1. Traverse the list\n";
  cout<<"2. Insert an element in the list\n";
  cout<<"3. Delete an element from the list\n";
  cin>>choice;
  if(choice==1)
  Traverse_DLL(list);
  else if(choice==2)
  {
   cout<<"Choose: \n";
   cout<<"1. Insert an element before a particular node\n";
   cout<<"2. Insert an element after a particular mode\n";
   cin>>inschoice;
   if(inschoice==1)
   {
    cout<<"Enter the element before which you want to enter the element:";
    cin>>key;
    cout<<"Enter the element you want to enter:";
    cin>>value;
    Insert_before_DLL(value,key);
    cout<<"Updated list:";
    Traverse_DLL(list);
   }
   else if(inschoice==2)
   {
    cout<<"Enter the element after which you want to enter the element:";
    cin>>key;
    cout<<"Enter the elemnent you want to insert:";
    cin>>value;
    Insert_after_DLL(list,value,key);
    cout<<"Updated list:";
    Traverse_DLL(list);
   }
   else
   cout<<"Wrong choice\n";
  }
  else if(choice==3)
  {
   cout<<"Enter the element you want to delete:";
   cin>>key;
   Delete_DLL(key);
   cout<<"Updated list:";
   Traverse_DLL(list);
  }
  else
  cout<<"Wrong choice\n";
  cout<<"Do you want to enter more? y or n-";
  cin>>c1;
  clrscr();
 }while(c1=='y'||c1=='Y');
 getch();
}

