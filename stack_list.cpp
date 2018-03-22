/*Stack as an Array*/

#include<iostream>
#include<conio.h>
#include<process.h>

using namespace std;

int Push(int [],int& ,int);
int Pop(int [],int&);
void Display(int [],int);

const int size=50;
int main()
{ int stack[size],top=-1,item,res;
  char ch='y';
  while(ch=='y'||ch=='Y')
  { cout<<"\nEnter the ITEM for insertion-";
    cin>>item;
    res=Push(stack,top,item);
    if(res==-1)
    {   cout<<"\nStack cannot be formed as the stack is overflow!!!";
         exit(1);
	}  
	cout<<"\nThe stack is now-"<<"\t";
	Display(stack,top);
	cout<<"\nWant to insert more elements??(y/n)";
	cin>>ch;
  }
  cout<<"\nNow the deletion of elements begin!";
  ch='y';
  while(ch=='y'||ch=='Y')
  { res=Pop(stack,top);
    if(res==-1)
    { cout<<"\nThe stack is underflow!!";
      exit(1);
	}
	else
	{ cout<<"\nThe element deleted is-"<<res;
	  cout<<endl;
	  cout<<"The stack is now-"<<"\t";
	  Display(stack,top);
	}
	cout<<"\nWant to delete more elements???(y/n)";
	cin>>ch;
  }
  return 0;
}

int Push(int stack[],int &top,int ele)
{ if(top==size-1)
   return -1;
  else
  { top=top+1;
    stack[top]=ele ;
   } 
  return 0; 
}

int Pop(int stack[],int &top)
{ int ret;
  if(top==-1)
  return -1;
  else
  { ret=stack[top];
    top=top-1;
  }
  return ret;
  
}

void Display(int stack[],int top)
{ if(top==-1)
  return ;
  cout<<stack[top]<<"<--"<<endl;
  for(int i=top-1;i>=0;i--)
  cout<<stack[i]<<endl;
  
}
