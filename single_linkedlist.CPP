#include<iostream>
#include<conio.h>

using namespace std;

struct NODE
{  int info;
   NODE *next;
}*list;

void show_list(NODE *list);

void push(int x)
{ NODE *temp,*temp1;
  temp=new NODE;
  temp->info=x;
  temp->next=NULL;
  temp1=list;
  while(temp1->next!=NULL)
     temp1=temp1->next;
     
  temp1->next=temp;
  temp->next=NULL;
     
}

void insert_first(NODE *list,int i)
{ NODE *temp;
 temp=new NODE;
 temp->info=i;
 temp->next=list;
 list=temp;
}

void Insert_before(NODE *list,int i, int key)
{ 
  NODE *temp,*temp1,*previous;
  temp=new NODE;
  temp->info=i;
  temp->next=NULL;
  temp1=list;
  if(temp1->info==key)
  {   temp->next=list;
      list=temp;
      cout<<list->info;
  }
  else
  { while(temp1->info!=key&& temp1->next!=NULL)
    { previous=temp1;
      temp1=temp1->next;
    }
    if(temp1->info==key)
    { temp->next=temp1;
      previous->next=temp;
	}
    else
      cout<<"\nSorry the key is not found";
        
  }
    
}
void Insert_after(NODE *list, int i, int key)
{ NODE *temp,*temp1;
  temp=new NODE;
  temp->info=i;
  temp->next=NULL;
  temp1=list;
  while(temp1->info!=key && temp1->next!=NULL)
  {  temp1=temp1->next;
     
  }
  if(temp1->info==key)
  { temp->next=temp1->next;
    temp1->next=temp;
    
  }
  else
  cout<<"\nkey not present!!!";
  
}

void Delete_Node(NODE *list,int key)
{  NODE *temp, *previous;
   temp=list;
   if(temp->info==key)
   { list=list->next;
     delete temp;
	} 
   else
   { while(temp->info!=key&& temp->next!=NULL)
     { previous=temp;
       temp=temp->next;
       
	 }
     if(temp->info==key)
	 { previous->next=temp->next;
	   delete temp;
	 }	   
	 else
	 cout<<"\nyou have entered wrong key!!!";  
   }	
}

void search(NODE *list,int i)
{ NODE *temp;
  int flag=0;
  temp=list;
  while(temp!=NULL)
  { if(temp->info==i)
    { flag=flag+1;
      break;
	}
	
	temp=temp->next;
  }
  if(flag==1)
  cout<<"\nfound";
  else
  cout<<"\nNot found";
  
}

void Reverse(NODE *list)
{ NODE *currnode,*prevnode,*nextnode;
  currnode=list;
  prevnode=NULL;
  while(currnode!=NULL)
  { nextnode=currnode->next;
    currnode->next=prevnode;
    prevnode=currnode;
    currnode=nextnode;
  }
  list=prevnode;
  show_list(list);
  
}

void show_list(NODE *list)
{ NODE *temp;
  temp=list;
  while(temp!=NULL)
  { cout<<temp->info<<"->";
    temp=temp->next;
  }
  cout<<"!!!";
}
                      
int main()
{  
   list=new NODE;
   int value,x;
   char c;
   cout<<"\nEnter the value for the new node-";
   cin>>value;
   list->info=value;
   list->next=NULL;
   cout<<"\nDo you want to enter more?"<<"\t";
   cin>>c;
   while(c=='y'||c=='Y')
   { cout<<"\nEnter values-";
     cin>>x;
	 push(x);
	 cout<<"\nMore??"<<"\t";
	 cin>>c;
	      
   } 
   char p;
   do{   
   
   cout<<"\nEnter 1 for inserting value before a particular node.";
   cout<<"\nEnter 2 for inserting value after a particular node.";
   cout<<"\nEnter 3 for deleting node.";
   cout<<"\nEnter 4 for searching a particular value in the list.(Remember this will only run when there are more than 2 elements in the list)";
   cout<<"\nEnter 5 for reversing the list.";
   cout<<"\nEnter your choice-";
   cin>>x;
      if(x==1)
	   { int i,key;
        cout<<"\nEnter the value you want to insert-";
        cin>>i;
        cout<<"\nEnter the key before which you want to insert the value-";
	    cin>>key;
		Insert_before(list,i,key);
	    show_list(list);
	    
	   }
	  else if (x==2)
	     {    int i,key;
	          cout<<"\nEnter the value you want to insert-";
			  cin>>i;
			  cout<<"\nEnter the key after which you want to insert the value-";
			  cin>>key;
			  Insert_after(list,i,key);
			  show_list(list);
         }
	 else if(x==3)
	     {    int key;
		      cout<<"\nEnter the key you want to delete- ";
	          cin>>key;
			  Delete_Node(list,key);
			  show_list(list);
	     }
	 else if(x==4)
	     {    int i;
	          cout<<"\nEnter the value you want to search in list-";
			  cin>>i;
			  search(list,i);
	     }
     else if(x==5)
	     {
		    Reverse(list);
		    cout<<"\nThe array after reversing will be-";
		   
	        
		 }
	 else
	  cout<<"\nyou have entered wrong choice";
	  
	  cout<<"\nDo you want to add more operations?";
	  cin>>p;
    }while(p=='y'||p=='Y');
   
 
 return 0;
}


