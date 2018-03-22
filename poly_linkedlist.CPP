#include<iostream.h>
#include<conio.h>
//using namespace std;
struct node
{
 int coff,pow;
 node *next;
};
node *list,*list1,*list2;
int main()
{
 clrscr();
 int n,m,i;
 node *temp,*temp1,*temp2,*temp3;
 cout<<"Enter no. of terms in 1st polynomial: ";
 cin>>m;
 list1=new node;
 cout<<"Enter the coefficients n degrees in 1st polynomial: ";
 cin>>list1->coff>>list1->pow;
 temp=list1;
 temp->next=NULL;
 for(i=0;i<m-1;i++)
 {
  temp1=new node;
  cin>>temp1->coff>>temp1->pow;
  temp1->next=NULL;
  temp->next=temp1;
  temp=temp1;
 }
 cout<<"Enter the no of terms in 2nd polynomial: ";
 cin>>n;
 list2=new node;
 cout<<"Enter the coefficients n degrees in 2nd polynomial: ";
 cin>>list2->coff>>list2->pow;
 temp=list2;
 temp->next=NULL;
 for(i=0;i<n-1;i++)
 {
  temp1=new node;
  cin>>temp1->coff>>temp1->pow;
  temp1->next=NULL;
  temp->next=temp1;
  temp=temp1;
 }
 temp1=list1;
 temp2=list2;
 int c=0;
 list=new node;
 while(temp1!=NULL&&temp2!=NULL)
 {
  if(temp1->pow==temp2->pow)
  {
   if(c==0)
   {
    list->pow=temp1->pow;
    list->coff=temp1->coff+temp2->coff;
    temp3=list;
    temp3->next=NULL;
    c++;
   }
   else
   {
    temp=new node;
    temp->pow=temp1->pow;
    temp->coff=temp1->coff+temp2->coff;
    temp3->next=temp;
    temp3=temp;
    temp3->next=NULL;
   }
   temp1=temp1->next;
   temp2=temp2->next;
  }
  else if(temp1->pow>temp2->pow)
  {
   if(c==0)
   {
    list->pow=temp1->pow;
    list->coff=temp1->coff;
    temp3=list;
    temp3->next=NULL;
    c++;
   }
   else
   {
    temp=new node;
    temp->pow=temp1->pow;
    temp->coff=temp1->coff;
    temp3->next=temp;
    temp3=temp;
    temp->next=NULL;
   }
   temp1=temp1->next;
  }
  else
  {
   if(c==0)
   {
    list->pow=temp2->pow;
    list->coff=temp2->coff;
    temp3=list;
    temp3->next=NULL;
    c++;
   }
   else
   {
    temp=new node;
    temp->pow=temp2->pow;
    temp->coff=temp2->coff;
    temp3->next=temp;
    temp3=temp;
    temp->next=NULL;
   }
   temp2=temp2->next;
  }
 }
 while(temp1!=NULL)
 {
  temp=new node;
  temp->pow=temp1->pow;
  temp->coff=temp1->coff;
  temp3->next=temp;
  temp3=temp;
  temp->next=NULL;
  temp1=temp1->next;
 }
 while(temp2!=NULL)
 {
  temp=new node;
  temp->pow=temp2->pow;
  temp->coff=temp2->coff;
  temp3->next=temp;
  temp3=temp;
  temp->next=NULL;
  temp2=temp2->next;
 }
 temp=list;
 cout<<"Resultant Polynomial: ";
 while(temp!=NULL)
 {
  cout<<temp->coff<<"x^"<<temp->pow;
  if(temp->next!=NULL)
  cout<<" + ";
  temp=temp->next;
 }
 getch();
 return 0;
}
