//queue as a linked list

#include<iostream>
#include<conio.h>

using namespace std;

struct Node
{ int info;
  Node *next;
};
Node *front,*rear;

void Enqueue(int x)
{ Node *temp;
  temp=new Node;
  temp->info=x;
  temp->next=NULL;
  if(front==NULL)
  { front=rear=temp;
    rear->next=NULL;
  }
  else
  { rear->next=temp;
    rear=rear->next;
  }
}
 
int Dequeue()
{  Node *temp;
   int value;
  if(front==rear)
  { temp=front;
    value=temp->info;
	front=rear=NULL;
	delete temp; 
  }
  else
  { temp=front;
    value=temp->info;
    front=front->next;
    delete temp;
  }
  return value;
 } 
 
 void Display()
 { Node *temp;
   temp=front;
   while(temp!=NULL)
   { cout<<temp->info<<"-->";
     temp=temp->next;
   }
   cout<<"!!!";
 }
 
int main()
{ int value;
  cout<<"\nEnter the value to be inserted in a queue-\t";
  cin>>value;
  Enqueue(value);
  cout<<"\nDo you want to enter more elements in a queue??";
  char ch;
  cin>>ch;
  while(ch=='y'||ch=='Y')
  { cout<<"\nEnter element:-\t";
    cin>>value; 
    Enqueue(value);
    cout<<"\nWant to enter more??";
    cin>>ch;
  }
  cout<<"\nDo you want to remove elements from the queue??";
  cin>>ch;
  while(ch=='y'||ch=='Y')
  { value=Dequeue();
    cout<<"\nThe deleted value is-\t"<<value;
	cout<<"\nWant to delete more???";
	cin>>ch; 
  }
  cout<<"\nThe whole queue after modifications is-\t";
  Display();
  return 0;
 } 
