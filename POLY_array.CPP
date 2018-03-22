#include<iostream.h>
#include<conio.h>

void main()
{ clrscr();
  int A1[10],A2[10],B1[10],B2[10],i,m,n,j,C1[10],C2[10];
  cout<<"\nEnter the terms present in the first polynomial-";
  cin>>n;
  cout<<"\nEnter the coefficients and powers of the first polynomial in the sorted form-";
  for(i=0;i<=n;i++)
  { cout<<"\ncoefficient-"<<i;
    cin>>A1[i];
    cout<<endl;
    cout<<"power-"<<i;
    cin>>A2[i];
    cout<<endl;
  }
  cout<<"\nEnter the terms present in the second polynomial-";
  cin>>m;
  cout<<"\nEnter the coefficients and powers of the second polynomial in the sorted form-";
  for(i=0;i<m;i++)
  {  cout<<"\ncoefficient-"<<i;
     cin>>B1[i];
     cout<<endl;
     cout<<"power-"<<i;
     cin>>B2[i];
     cout<<endl;
  }
       i=0;
       j=0;
       int k=0;
       while(i<n && j<m)
       { if(A2[i]>B2[j])
	 { C1[k]=A1[i];
	   C2[k]=A2[i];
	   k++;
	   i++;
	 }
	 else if(B2[j]>A2[i])
	 { C1[k]=B1[j];
	   C2[k]=B2[j];
	   k++;
	   j++;
	 }
	 else if(A2[i]==B2[j])
	 { C1[k]=A1[i]+B1[j];
	   C2[k]=A2[i];
	   k++;
	   i++;
	   j++;
	 }
       }
       if(i==n)
       { while(j<m)
	 { C1[k]=B1[j];
	   C2[k]=B2[j];
	   k++;
	   j++;
	 }
       }
       if(j==m)
       { while(i<n)
	 { C1[k]=A1[i];
	   C2[k]=A2[i];
	   k++;
	   i++;
	 }
       }

       cout<<"\nThe addition of the two polynomial's coefficient is:";
       for(j=0;j<k;j++)
       { cout<<C1[j]<<"   "<<C2[j];
	 cout<<endl;
       }

  getch();
}