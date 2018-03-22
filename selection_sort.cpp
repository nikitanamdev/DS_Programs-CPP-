#include<iostream>
#include<conio.h>

using namespace std;

void Selection_Sort(int A[50],int size) 
{  int min , pos;
    
   for (int i = 0; i < size-1; i++)
   {   min = A[i];
       pos = i;
       for(int j = i+1; j < size; j++)
	   { if(A[j] < min)
	     { min = A[j];
		   pos = j; 
	     }
	   } 
	   int t;
	   t = A[i];
	   A[i] = A[pos];
	   A[pos] = t;
	    

   }
   
       cout << "\nThe sorted array in ascending order is shown below:";
       for(int i = 0; i < size; i++)
       {  cout << A[i] << endl;
	   }
	   
	   cout << "\nThe sorted array in descending order is shown below:";
	   for(int j = size-1; j >= 0; j-- )
	   { cout << A[j] << endl;
	   }
}

int main()
{  int A[50] , size , i , j;
   cout << "\nEnter the size for the array to be entered:";
   cin >> size;
   cout << "\nEnter the array elements now:";
   for(i=0 ; i < size; i++)
   { cin >> A[i];
   } 
   
   Selection_Sort(A,size);
   return 0; 
}
