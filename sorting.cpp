//implementing sorting

#include<iostream>
#include<conio.h>

using namespace std;

void BubbleSort(int A[],int &size)
{ 
  for(int i=0;i<size;i++)
   { for(int j=0;j<size-1;j++)
      { if(A[j+1]<A[j])
          swap(A[j+1],A[j]);
      }
   }
}

void swap(int &a,int &b)
{ int t;
  t=a;
  a=b;
  b=t;
  
}

void InsertionSort(int A[],int &size)
{ int key;
  for(int j=2;j<size;j++)
  {  key=A[j];
     int i=j-1;
     while(i>0 && A[i]>key)
     { 
       A[i+1]=A[i];
       i--;
     }
     A[i+1]=key;
  }
}

int Pivot_list(int A[],int a,int b)
{ int Pivot_value=A[a];
  int Pivot_point=a;
  for(int i=a+1;i<b;i++)
  { 
    if(A[i]<Pivot_value)
      { Pivot_point++;
        swap(A[Pivot_point],A[i]);
      }
  }
  swap(A[a],A[Pivot_point]);
  
  return Pivot_point;
}


void QuickSort(int A[],int first,int last)
{ int pivot;
  if(first<last)
   { 
     pivot=Pivot_list(A,first,last);
     QuickSort(A,first,pivot-1);
     QuickSort(A,pivot+1,last);
   }
}

void Max_heapify(int A[],int i,int hs)
{ int largest;
  int l=2*i;
  int r=2*i+1;
  if(l<hs && A[l]>A[i])
    largest=l;
  else
   largest=i;
   
  if(r<hs && A[r]>A[largest])
    largest=r;   
  if(largest!=i)
  { swap(A[i],A[largest]);
    Max_heapify(A,largest,hs); 
  } 
}

void Build_Maxheap(int A[],int n)
{ 
  int hs=n;
  for(int i=n/2;i>=0;i--)
  { 
    Max_heapify(A,i,hs);
  }
}

void HeapSort(int A[],int size)
{ int hs=size;
  Build_Maxheap(A,size);
  for(int i=size-1;i>0;i--)
  { 
    swap(A[0],A[i]);
    hs--;
    Max_heapify(A,0,hs);
  }
}

void Merge(int A[],int s1,int e1,int s2,int e2,int size)
{ 
  int i=0,finalstart=s1,finalend=e2;
  int result[size];
  while(s1<=e1 && s2<=e2)
  { 
   if(A[s1]<A[s2])
   { result[i]=A[s1];
     i++;
     s1++;
   }
   else
   { result[i]=A[s2];
     i++;
     s2++;
   }
  }
  if(s2>e2)
  { for(int j=s1;j<=e1;j++)
    { result[i]=A[j];
      i++;
    }
  }
  else if(s1>e1)
  { for(int j=s2;j<=e2;j++)
    { result[i]=A[j];
      i++;
    }
  }
  int k=0;
  for(int j=finalstart;j<=finalend;j++)
  { A[j]=result[k];
    k++;
  }
}


void MergeSort(int A[],int first,int last,int size)
{ if(first<last)
  { int mid=(first+last)/2;
    MergeSort(A,first,mid,size);
	MergeSort(A,mid+1,last,size);
	
	Merge(A,first,mid,mid+1,last,size); 
  }
}


int main()
{ 
  int A[20],n;
  cout<<"\nEnter the size of the Array-\t";
  cin>>n;
  cout<<"\nNow Enter the array elements-\t";
  for(int i=0;i<n;i++)
  cin>>A[i];
  int ch;
  char c='y';
  cout<<endl;
  do{
  cout<<"\nEnter 1 for performing Bubble sort.";
  cout<<"\nEnter 2 for performing Insertion sort.";
  cout<<"\nEnter 3 for performing Quick sort.";
  cout<<"\nEnter 4 for performing Heap sort.";
  cout<<"\nEnter 5 for performing Merge sort.";
  cout<<"\nEnter your choice.\t";
  cin>>ch;
  if(ch==1)
  {
  BubbleSort(A,n);
  cout<<"\nArray after bubble sort:\t";
  for(int i=0;i<n;i++)
  cout<<A[i]<<endl;
  }
  else if(ch==2)
  { InsertionSort(A,n);
    cout<<"\nArray after Insertion sort:\t";
    for(int i=0;i<n;i++)
    cout<<A[i]<<endl;
  }
  else if(ch==3)
  { QuickSort(A,0,n);
    cout<<"\nArray after Quick sort:\t";
    for(int i=0;i<n;i++)
    cout<<A[i]<<endl;
  }
  else if(ch==4)
  { HeapSort(A,n);
    cout<<"\nArray after Heap sort:\t";
    for(int i=0;i<n;i++)
    cout<<A[i]<<endl;
  }
  else if(ch==5)
  { MergeSort(A,0,n-1,n);
    cout<<"\nArray after Merge sort:\t";
    for(int i=0;i<n;i++)
    cout<<A[i]<<endl;
  }
  else
  cout<<"\nYou have entered wrong choice.";
  cout<<"\nDo you want to perform more operations(y/n):\t ";
  cin>>c;
}while(c=='y'||c=='Y');
  return 0; 
}
