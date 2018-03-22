#include<iostream.h>
#include<conio.h>

void main()
{  clrscr();
   int A[100],B[100],n,m;
   cout<<"Enter the size of first array:";
   cin>>n;
   cout<<"\nEnter the size of second array:";
   cin>>m;
   cout<<"\nEnter the elements in first array in sorted form-";
   for(int i=0;i<n;i++)
   cin>>A[i];
   cout<<"\nEnter the elements in second array in sorted form-";
   for(i=0;i<m;i++)
   cin>>B[i];
   int C[100];

   if(A[0]<A[n-1]&&B[0]<B[m-1])
   { int j,k;
     i=j=k=0;
     while(i<n&&j<m)
     { if(A[i]<B[j])
       { C[k]=A[i];
	 k++;
	 i++;
       }
       else
       { C[k]=B[j];
	 k++;
	 j++;
       }
     }
     if(i==n)
     { while(j<=m)
       { C[k]=B[j];
	 k++;
	 j++;
       }
     }
     else if(j==m)
     { while(i<=n)
       { C[k]=A[i];
	 k++;
	 i++;
       }
     }
     cout<<"\n The merge array is-";
     for(i=0;i<(n+m);i++)
     cout<<C[i]<<endl;
  }

  else if(A[0]>A[n-1]&&B[0]>B[m-1])
  {  int i,j,k;
     i=j=k=0;
    while(i<n && j<m)
    {  if(A[i]>B[j])
       { C[k]=A[i];
	 k++;
	 i++;
       }
       else
       { C[k]=B[j];
	 k++;
	 j++;
       }
    }
    if(i==n)
    { while(j<m)
      {  C[k]=B[j];
	 k++;
	 j++;
      }
    }
    else if(j==m)
    { while(i<n)
      { C[k]=A[i];
	k++;
	i++;
      }
    }
    cout<<"\nThe merge array is-";
    for(i=0;i<(m+n);i++)
    cout<<C[i]<<endl;
 }

 else if(A[0]<A[n-1] && B[0]>B[m-1])
    { int i,j,k;
      i=k=0;
      j=m-1;
   while(i<n && j>=0)
    {  if(A[i]<B[j])
       { C[k]=A[i];
	 k++;
	 i++;
       }
       else
       { C[k]=B[j];
	 k++;
	 j--;
       }
    }
    if(i==n)
    { while(j>=0)
      {  C[k]=B[j];
	 k++;
	 j--;
      }
    }
    else if(j==0)
    { while(i<n)
      { C[k]=A[i];
	k++;
	i++;
      }
    }
    cout<<"\nThe merge array in ascending order is-";
    for(i=0;i<m+n;i++)
    cout<<C[i]<<endl;

    j=k=0;
    i=n-1;
   while(i>=0 && j<m)
    {  if(A[i]<B[j])
       { C[k]=B[j];
	 k++;
	 j++;
       }
       else
       { C[k]=A[i];
	 k++;
	 i--;
       }
    }
    if(i==0)
    { while(j<m)
      {  C[k]=B[j];
	 k++;
	 j++;
      }
    }
    else if(j==m)
    { while(i>=0)
      { C[k]=A[i];
	k++;
	i--;
      }
    }
    cout<<"\nThe merge array in descending order is-";
    for(i=0;i<m+n;i++)
    cout<<C[i]<<endl;
 }


 else if(A[0]>A[n-1] && B[0]<B[m-1])
    { int j,k;
      j=k=0;
      i=n-1;
   while(i>=0 && j<m)
    {  if(A[i]<B[j])
       { C[k]=A[i];
	 k++;
	 i--;
       }
       else
       { C[k]=B[j];
	 k++;
	 j++;
       }
    }
    if(i==0)
    { while(j<m)
      {  C[k]=B[j];
	 k++;
	 j++;
      }
    }
    else if(j==m)
    { while(i>=0)
      { C[k]=A[i];
	k++;
	i--;
      }
    }
    cout<<"\nThe merge array in ascending order is-";
    for(i=0;i<m+n;i++)
    cout<<C[i]<<endl;


     j=m-1;
     i=k=0;
   while(i<n && j>=0)
    {  if(A[i]>B[j])
       { C[k]=A[i];
	 k++;
	 i++;
       }
       else
       { C[k]=B[j];
	 k++;
	 j--;
       }
    }
    if(i==n)
    { while(j>=0)
      {  C[k]=B[j];
	 k++;
	 j--;
      }
    }
    else if(j==0)
    { while(i<n)
      { C[k]=A[i];
	k++;
	i++;
      }
    }
    cout<<"\nThe merge array in descending order is-";
    for(i=0;i<m+n;i++)
    cout<<C[i]<<endl;
 }

getch();
}
