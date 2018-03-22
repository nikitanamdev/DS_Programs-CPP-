#include<iostream.h>
#include<conio.h>

void main()
{ clrscr();
  int A[10][10],B[10][10],m,n,i,j,C[10][10],a,b,D[10][10];
  cout<<"\nEnter the size of the first array-";
  cout<<"\nFirst enter the rows:";
  cin>>m;
  cout<<"\nNow enter the columns :";
  cin>>n;
  cout<<"\nEnter the size of the second array-";
  cout<<"\nFirst enter the rows:";
  cin>>i;
  cout<<"\nNow enter the columns:";
  cin>>j;
  cout<<"\nEnter the elements in the first matrix:";
  for(a=0;a<m;a++)
   for(b=0;b<n;b++)
     cin>>A[a][b];

  cout<<"\nEnter the elements in the second matrix:";
  for(a=0;a<i;a++)
   for(b=0;b<j;b++)
     cin>>B[a][b];


  if(m==i &&n==j)
  { cout<<"\nTwo operations can be done: 1.Addition 2.Substraction ";
    for(a=0;a<m;a++)
    { for(b=0;b<n;b++)
      C[a][b]=A[a][b]+B[a][b];
    }
    cout<<"\nThe addition of the matrix is:";
    for(a=0;a<m;a++)
    {  for(b=0;b<n;b++)
	 { cout<<C[a][b]<<"  ";
	 }
      cout<<endl;
    }
    for(a=0;a<m;a++)
    {   for(b=0;b<n;b++)
	C[a][b]=A[a][b]-B[a][b];
    }
    cout<<"\nThe substraction of the matrix is:";
    for(a=0;a<m;a++)
    { for(b=0;b<n;b++)
	{  cout<<C[a][b]<<"  ";
	}
      cout<<endl;
    }
  }
  else
   cout<<"\n Then Transpose and multiplication operation can be performed.\n";

  if(n==i)
  { for(a=0;a<m;a++)
    { for(b=0;b<j;b++)
      { C[a][b]=0;
	for(int k=0;k<n;k++)
	C[a][b]+=A[a][k]*B[k][b];
      }
    }
    cout<<"\n The multiplication of the matrix is";
    for(a=0;a<m;a++)
    { for(b=0;b<j;b++)
      cout<<C[a][b]<<"  ";
      cout<<endl;
    }
  }
  else
  cout<<"\nSorry multiplication can't be done!!!";


    for(a=0;a<n;a++)
    for(b=0;b<m;b++)
    C[a][b]=A[b][a];

    cout<<"\nThe transpose of the first matrix is:";
    for(a=0;a<n;a++)
    { for(b=0;b<m;b++)
      cout<<C[a][b]<<"  ";
      cout<<endl;
    }

    for(a=0;a<j;a++)
    for(b=0;b<i;b++)
    D[a][b]=B[b][a];

    cout<<"\nThe transpose of the second matrix is:";
    for(a=0;a<j;a++)
    { for(b=0;b<i;b++)
      cout<<D[a][b]<<"  ";
      cout<<endl;
    }

  getch();
}
