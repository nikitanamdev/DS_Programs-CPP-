//queue as an Array
#include<iostream>
#include<conio.h>

using namespace std;
const int size=50;
int q[size],rear=-1,front=0;
static int n=0;
int Enqueue(int x)
{ if(rear==size-1)
  cout<<"\nQueue is overflow";
  else
  { rear=rear+1;
    q[rear]=x;
  }
}
int Dequeue()
{ int item;
  if(front==(rear+1))
  cout<<"\n Queue is Empty";
  else
  { item=q[front];
    front = front+1;
    return item;
  }
}

void display()
{ cout<<"\nQueue is: ";
  for (int i=front;i<=rear;i++)
  cout<<q[i]<<"-->";
  cout<<"!";
  cout<<endl;
}

int main()
{ int value,m;
  cout<<"\nEnter the first value in the queue-\t";
  cin>>value;
  rear=0;
  q[front]=q[rear]=value;
  
  cout<<"\nDo you want to add more elements in the queue?";
  char ch;
  cin>>ch;
  while(ch=='y'||ch=='Y')
  { cout<<"\nEnter element:\t";
    cin>>value;
	Enqueue(value);
	
	/*if(Enqueue(value)==-1)
	cout<<"\nQueue is overflow!!!";
	
	n++;
	*/
	cout<<"\nWant to enter more??";
	cin>>ch;
  }
  int p;
  do
  { cout<<"\nEnter 1 to add more elements.";
    cout<<"\nEnter 2 to delete elements.";
    cout<<"\nEnter 3 to display the list.";
    cout<<"\nEnter your choice\t";
    cin>>p;
    if(p==1)
    { cout<<"\nEnter the value you want to add-\t";
      cin>>value;
      Enqueue(value);
      /*n++;
      if(Enqueue(value)==-1)
      cout<<"\nQueue is overflow!!!";*/    
	}
	else if(p==2)
	{ m=Dequeue();
	  /*
	  if(m==-1)
	  cout<<"\nThe Queue is empty!!!";*/
	  
	  cout<<"\nOne item deleted!";
	  cout<<"\nAnd the item deleted is-\t"<<m;
      
	}
	else if(p==3)
	{ display();
	}
	else
	cout<<"\nyou have entered wrong choice!!";
	cout<<"\nWant to add more operations??";
	cin>>ch;
  }while(ch=='y'||ch=='Y');
  return 0;
}
