#include<iostream.h>
#include<conio.h>

void main()
{ clrscr();
  int i,size,A[100];
  cout<<"Enter the size of an array-";
  cin>>size;
  cout<<"\nEnter the array elements - ";
  for(int a=0;a<size;a++)
  cin>>A[a];

  cout<<"Enter 1 for traversal of an array\n";
  cout<<"Enter 2 for printing an item by selecting any random position\n";
  cout<<"Enter 3 for searching a particular element in an array\n";
  cout<<"Enter 4 for inserting an element at any position inside array\n";
  cout<<"Enter 5 for deleting an element from a particular position\n";
  cout<<"Now please enter the any number from 1 to 5=";

  cin>>i;
  switch(i)
  { case 1: for(a=0;a<size;a++)
	    cout<<A[a];
	    break;
    case 2: int pos;
	    cout<<"\n Now enter the element position-";
	    cin>>pos;
	    cout<<endl<<A[pos];
	    break;
    case 3: int item;
	    cout<<"\n Enter the item to be search for-";
	    cin>>item;
	    for(a=0;a<size;a++)
	    { if(item==A[a])
	     { cout<<"Found";
	       break;
	     }
	     else
	     cout<<"\n not found";

	    }
	     break;
    case 4:
	    cout<<"\n Enter the item to be inserted:";
	    cin>>item;
	    cout<<"\n Enter the position at which item to be placed:";
	    cin>>pos;

	    for(a=size-1;a>=pos-1;a--)
	    { A[a+1]=A[a];
	    }
	    A[pos-1]=item;
	    size+=1;
	    cout<<"\nFinal array is:";
	    for(a=0;a<size;a++)
	    cout<<A[a]<<endl;
	    break;
    case 5:
	    cout<<"\n Enter the position from which the element is to be deleted:";
	    cin>>pos;
	    for(a=pos-1;a<size-1;a++)
	    A[a]=A[a+1];
	    size=size-1;
	    cout<<"\n Final array is:";
	    for(a=0;a<size;a++)
	    cout<<A[a]<<endl;
	    break;
    default: cout<<"\n You have filled wrong choice!!!";

}
getch();
}