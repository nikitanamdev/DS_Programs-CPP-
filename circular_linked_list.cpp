//circular linked list program
#include<iostream>
#include<conio.h>

using namespace std;

struct Node
{ int info;
  Node *next;
};
Node *list;

void Push(int x)
{ Node *temp,*temp1;
  temp1=list;
  temp=new Node;
  temp->info=x;
  temp->next=NULL;
  while(temp1->next!=list)
  temp1=temp1->next;
  temp1->next=temp;
  temp->next=list; 
}

void Show()
{ Node *temp;
  temp=list;
  while(temp->next!=list)
  { cout<<temp->info<<"->";
    temp=temp->next;
    
  }
  cout<<temp->info<<"!!!";
}

void Insertbefore(int x,int key)
{ Node *prev,*temp,*temp1;
  prev=list;
  temp=new Node;
  temp->info=x;
  temp->next=NULL;
  temp1=list;
  while(prev->next!=list)
  prev=prev->next;
  while(temp1->next!=list && temp->info!=key)
  { prev=temp1;
    temp1=temp1->next;
    
  }
  if(temp1->info==key)
  { temp->next=temp1;
    prev->next=temp;
	if(temp1==list)
	list=temp;
  }
  else if(temp1->next==list)
  cout<<"\nKey not found!!!";
  
}

void Insertafter(int x,int key)
{ Node *temp,*temp1;
  temp=new Node;
  temp->info=x;
  temp->next=NULL;
  temp1=list;
  while(temp1->info!=key && temp1->next!=list)
  temp1=temp1->next;
   
  if(temp1->info==key)
  { temp->next=temp1->next;
    temp1->next=temp;
  }
  else
  cout<<"\nKey not found!!!";
    
}

void Delete(int key)
{ Node *temp,*prev;
  temp=list;
  if(temp->info==key)
  { list=list->next;
    delete temp;
  }
  else
  { while(temp->info!=key && temp->next!=list)
    { prev=temp;
      temp=temp->next;
	}
	if(temp->info==key)
	{ prev->next=temp->next;
	  delete temp; 
	}
	else
	cout<<"\nKey not found!!!";
  }
}

int main()
{ list=new Node;
  int value,x;
  char c;
  cout<<"\nEnter the value for the first Node-\t";
  cin>>value;
  list->info=value;
  list->next=NULL;
  cout<<"\nDo you want to enter more?(y/n)\t";
  cin>>c;
  
  while(c=='y'||c=='Y')
  { cout<<"\nEnter values-\t";
    cin>>x;
    Push(x);
    cout<<"\nWant to enter more?\t";
    cin>>c;
  }
  char p;
  int a,key;
  do{ 
     cout<<"\nEnter 1 for inserting values in the linked list";
     cout<<"\nEnter 2 for deleting the values from the linked list";
     cout<<"\nEnter 3 for traversing the list";
     cout<<"\nEnter your choice:\t";
     cin>>x;
     if(x==1)
     { cout<<"\nEnter 1 for inserting an element before a particular node. ";
       cout<<"\nEnter 2 for inserting an element after a particular node.";
       cout<<"\nEnter your choice:\t";
       cin>>a;
       if(a==1)
       { cout<<"\nEnter the element you want to insert-\t";
         cin>>value;
         cout<<"\nEnter the element before which you want to insert the element-\t";
         cin>>key;
         Insertbefore(value,key);
         cout<<"\nUpdated list-\t";
         Show();
	   }
	   else if(a==2)
	   { cout<<"\nEnter the element you want to insert-\t";
         cin>>value;
         cout<<"\nEnter the element after which you want to insert the element-\t";
         cin>>key;
         Insertafter(value,key);
         cout<<"\nUpdated list-\t";
         Show();
	   }
	   else
	   cout<<"\nWrong choice!!!";
      }
      else if(x==2)
      { cout<<"\nEnter the element you want to delete-\t";
        cin>>key;
        Delete(key);
        cout<<"\nUpdated list:\t";
        Show();
        
	  }
	  else if(x==3)
	  { cout<<"\nThe list is:-\t";
	    Show();
	  }
	  else
	  cout<<"\nYou have entered wrong choice!!";
	  
	  cout<<"\nDo you want to operate more ??(y/n)\t";
	  cin>>p;
	 }while(p=='y'||p=='Y');
	 
	 return 0;
	 
  }

