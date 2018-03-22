#include<iostream.h>
#include<conio.h>

void main()
{ clrscr();
  int A[100], i, size, item, l, u, mid;
  cout<<"Enter the size of an array-";
  cin>>size;
  cout<<"\nEnter the elements in the array in sorted form:";
  for(i=0;i<size;i++)
  cin>>A[i];
  cout<<"\nNow enter the element you want to search in the array-";
  cin>>item;
  l=0;
  u=size-1;
  while(l<=u)
  { mid=(l+u)/2;
    if(item==A[mid])
    {  cout<<"\nthe position of the element you have searched is-"<<mid+1;
       break;
    }
    else if(item<A[mid])
	 u=mid-1;
    else if(item>A[mid])
	 l=mid+1;
  }
    if(item!=A[mid])
    cout<<"\n!!!Not found!!!";

getch();
}

