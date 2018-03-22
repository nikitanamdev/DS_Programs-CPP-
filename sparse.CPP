#include<iostream.h>
#include<conio.h>
void main()
{
char c;
int A[10][10],B[10][10],C[10][10],CA[10][10],CB[10][10],n,m,i,j,k1,k2,k,ch;
do
{
cout<<"1.Enter 1 if you want to convert a sparse matrix into condensed form";
cout<<"\n2.Enter 2 if you want to add two sparse matrices in condensed form";
cout<<"\n3.Enter 3 if you want to get the transpose of the sparse matrix in condensed form";
cin>>ch;
if(ch==1)
{
cout<<"\nEnter the number of rows for sparse matrix : ";
cin>>n;
cout<<"\nEnter the number of columns for sparse matrix : ";
cin>>m;
cout<<"\nEnter the elements of sparse matrix : ";
for(i=0;i<n;i++)
for(j=0;j<m;j++)
cin>>A[i][j];
CA[0][0]=n;
CA[0][1]=m;
k=0;
for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   {
   if(A[i][j]!=0)
    {
     k++;
     CA[k][0]=i;
     CA[k][1]=j;
     CA[k][2]=A[i][j];
    }
   }
  }
  CA[0][2]=k;
  cout<<"\nThe sparse matrix in condensed form is : ";
  for(i=0;i<k+1;i++)
  {
  for(j=0;j<3;j++)
  {
  cout<<CA[i][j]<<" ";
  } cout<<endl;
  }
 }
 else if(ch==2)
 {
cout<<"\nEnter the number of rows for sparse matrix : ";
cin>>n;
cout<<"\nEnter the number of columns for sparse matrix : ";
cin>>m;
cout<<"\nEnter the elements of first sparse matrix : ";
for(i=0;i<n;i++)
for(j=0;j<m;j++)
cin>>A[i][j];
CA[0][0]=n;
CA[0][1]=m;
k1=0;
cout<<"\nEnter the elements of second sparse matrix : ";
for(i=0;i<n;i++)
for(j=0;j<m;j++)
cin>>B[i][j];
CB[0][0]=n;
CB[0][1]=m;
k2=0;
for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   {
   if(A[i][j]!=0)
    {
     k1++;
     CA[k1][0]=i;
     CA[k1][1]=j;
     CA[k1][2]=A[i][j];
    }
   }
  }
  CA[0][2]=k1;
  /*cout<<"\nThe first sparse matrix in condensed form is : ";
  for(i=0;i<k1+1;i++)
  {
  for(j=0;j<3;j++)
  {
  cout<<CA[i][j]<<" ";
  } cout<<endl;
  }*/
  for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   {
   if(B[i][j]!=0)
    {
     k2++;
     CB[k2][0]=i;
     CB[k2][1]=j;
     CB[k2][2]=B[i][j];
    }
   }
  }
  CB[0][2]=k2;
 /*cout<<"\nThe second sparse matrix in condensed form is : ";
  for(i=0;i<k2+1;i++)
  {
  for(j=0;j<3;j++)
  {
  cout<<CB[i][j]<<" ";
  } cout<<endl;
  }*/
  i=1;j=1;k=1;
  while(i<k1+1&&j<k2+1)
  {
   if(CA[i][0]<CB[j][0])
   {
     C[k][0]=CA[i][0];
     C[k][1]=CA[i][1];
     C[k][2]=CA[i][2];
     k++;i++;
   }
   else if(CA[i][0]>CB[j][0])
   {
     C[k][0]=CB[j][0];
     C[k][1]=CB[j][1];
     C[k][2]=CB[j][2];
     k++;j++;
   }
   else if(CA[i][0]==CB[j][0])
   {
    if(CA[i][1]<CB[j][1])
    {
     C[k][0]=CA[i][0];
     C[k][1]=CA[i][1];
     C[k][2]=CA[i][2];
     k++;i++;
    }
   else if(CA[i][1]>CB[j][1])
    {
     C[k][0]=CB[j][0];
     C[k][1]=CB[j][1];
     C[k][2]=CB[j][2];
     k++;j++;
    }
    else if(CA[i][1]==CB[j][1])
    {
     C[k][0]=CB[j][0];
     C[k][1]=CB[j][1];
     C[k][2]=CA[i][2]+CB[j][2];
     k++;i++;j++;
    }
   }
  }
 if(j==k2+1)
  {
  while(i<k1+1)
  {
    C[k][0]=CA[i][0];
     C[k][1]=CA[i][1];
     C[k][2]=CA[i][2];
     k++;
     i++;
  }
  }
  if(i==k1+1)
  {
  while(j<k2+1)
  {
     C[k][0]=CB[j][0];
     C[k][1]=CB[j][1];
     C[k][2]=CB[j][2];
     k++;j++;
  }
  }
  C[0][0]=CA[0][0];
  C[0][1]=CA[0][1];
  C[0][2]=k-1;
  cout<<"\nThe condensed matrix after addition : ";
  for(i=0;i<k;i++)
  {
  for(j=0;j<3;j++)
  {
   cout<<C[i][j]<<" ";
   }
   cout<<endl;
   }
   }
   else if(ch==3)
   {
   int T[10][10];
   cout<<"\nEnter the number of rows for sparse matrix : ";
   cin>>n;
   cout<<"\nEnter the number of columns for sparse matrix : ";
   cin>>m;
   cout<<"\nEnter the elements of sparse matrix : ";
   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   cin>>A[i][j];
   CA[0][0]=n;
   CA[0][1]=m;
   k=0;
for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   {
   if(A[i][j]!=0)
    {
     k++;
     CA[k][0]=i;
     CA[k][1]=j;
     CA[k][2]=A[i][j];
    }
   }
  }
  CA[0][2]=k;
  cout<<"\nThe sparse matrix in condensed form is : ";
  for(i=0;i<k+1;i++)
  {
  for(j=0;j<3;j++)
  {
  cout<<CA[i][j]<<" ";
  } cout<<endl;
  }
  for(i=0;i<k+1;i++)
  {
  T[i][0]=CA[i][1];
  T[i][1]=CA[i][0];
  T[i][2]=CA[i][2];
  }
  for(i=1;i<k;i++)
  {
  int min=T[i][0];
  int pos=i;
  for(j=i+1;j<k+1;j++)
  {
  if(T[j][0]<min)
  {
  min=T[j][0];
  pos=j;
  }
  }
  int t;
  t=T[i][0];
  T[i][0]=T[pos][0];
  T[pos][0]=t;
  t=T[i][1];
  T[i][1]=T[pos][1];
  T[pos][1]=t;
  t=T[i][2];
  T[i][2]=T[pos][2];
  T[pos][2]=t;
  }
  for(i=1;i<k;i++)
  {
  for(j=i+1;j<k+1;j++)
  {
   if(T[i][0]==T[j][0])
   {
   if(T[i][1]>T[j][1])
   {
   int e;
   e=T[i][1];
   T[i][1]=T[j][1];
   T[j][1]=e;
   e=T[i][2];
   T[i][2]=T[j][2];
   T[j][2]=e;
   }
   }
   }
   }
  cout<<"\nThe transpose of the sparse matrix is : ";
  for(i=0;i<k+1;i++)
  { for(j=0;j<3;j++)
  cout<<T[i][j]<<" ";
  cout<<endl;
  }
  }
  cout<<"Do you want to perform more...?????????\nEnter y or n";
  cin>>c;
  clrscr();
  } while(c=='y'||c=='Y');
 getch();
  }