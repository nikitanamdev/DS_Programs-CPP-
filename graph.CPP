#include<iostream.h>
#include<conio.h>
#include<process.h>
struct node
{
	int data;
	node *next;
};
node* list[10];
node *temp[10];
int count[10]={0,0,0,0,0,0,0,0,0,0};
int visit [10];
int q[10];
int front=0;
int rear=-1;
void enqueue(int z)
{
	if(rear==9)
	cout<<"Queue is full\n";
	else
	{
	rear=rear+1;
	q[rear]=z;
	}
}
int dequeue()
{
	if(front==rear+1)
	cout<<"Queue is empty\n";
	int x=q[front];
	front=front+1;
	return x;
}
void bfs_visit(int y)
{
	node *t;
	enqueue(y);
	while(front!=rear+1)
	{
	    int s=dequeue();
	    t=list[s];
	    while(t!=NULL)
	    {
		if(visit[t->data]==0)
		{
		    visit[t->data]=1;
		    enqueue(t->data);
		}
		t=t->next;
	     }
	     visit[s]=1;
	//     t->visit=1;
	     cout<<s<<"  ";
	 }
}
void dfs_visit(int g)
{
	node *t1;
	visit[g]=1;
	cout<<g<<"  ";
 //	t2=list[g]
 //	while(t2->data!=key)
   //	{
  //		t2=t2->next;
  //	}
  //	t2->v1;
	t1=list[g];
	while(t1!=NULL)
	{
	  if(visit[t1->data]==0)
	  {
	     dfs_visit(t1->data);
	  }
	  t1=t1->next;
	}
}
void setedge(int i,int j)
{
	node *temp1;
	temp1=new node;
	temp1->data=j;
	temp1->next=NULL;
	if(count[i]==0)
	{
		list[i]=temp1;
		temp[i]=list[i];
		count[i]++;
	}
	else
	{
		temp[i]->next=temp1;
		temp[i]=temp[i]->next;
		count[i]++;
	}
}
/*void printgraph(node* header[])
{       int i=0;
	while(header[i]!=NULL)
		{
			while(temp[i]!=NULL)
			{
			cout<<temp[i]<<"  ";
			temp[i]=temp[i]->next;
			}
			cout<<endl;
			i++;
		}

} */
void main()
{
	clrscr();
	int i,j,k,v,ch;
	char ans;
	node *temp1;
	cout<<"Enter the total number of vertex\n";
	cin>>v;
	cout<<"Now enter the edges\n";
	do
	{
		cout<<"Enter the start and end vertices of the edge\n";
		cin>>i>>j;
	    /*	temp1=new node;
		temp1->data=j;
		temp1->next=NULL;
		if(count[i]==0)
		{
			list[i]=temp1;
			temp[i]=list[i];
			count[i]++;
		}
		else
		{
			temp[i]->next=temp1;
			temp[i]=temp[i]->next;
			count[i]++;
		}
		*/
		setedge(i,j);
		setedge(j,i);
		cout<<"do u want to enter more\n";
		cin>>ans;
	}
	while(ans=='y'||ans=='Y');
	while(1)
	{
		cout<<"Enter 1 for Breadth First Traversal \n";
		cout<<"Enter 2 for Depth First Traversal \n";
		cout<<"Enter 3 for exit\n";
		cout<<"Enter your choice \n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"BFS TRAVERSAL \n";
			for(k=1;k<=v;k++)
			{
			  visit[k]=0;
			}
			for(k=1;k<=v;k++)
			{
			  if(visit[k]==0)
			  bfs_visit(k);
			}
			cout<<endl;
		}
		if(ch==2)
		{
			cout<<"DFS TRAVERSAL \n";
			for(k=1;k<=v;k++)
			{
			  visit[k]=0;
			}
			for(k=1;k<=v;k++)
			{
			  if(visit[k]==0)
			  dfs_visit(k);
			}
			cout<<endl;
		}
		if(ch==3)
		{
		exit(0);
		}
	}
	getch();
}





