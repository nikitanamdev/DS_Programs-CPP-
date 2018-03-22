//evaluation of the postfix expression
#include<iostream>
#include<conio.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include"stack.h"

using namespace std;
char *s='\0';
int nn=0;

char Postfix[size];
void setexpr(char *str)
{ 
  s=str;
}
void Postfix_eval()
{ int n1,n2,n3;
  while(*s)
  { 
	 if(isdigit(*s))
	 { nn=*s-'0';
	   Push(nn);
	 }
	 else
	 { n1=Pop();
	   n2=Pop();
	   switch(*s)
	   { 
	      case '+': n3=n1+n2;
	                break;
	      case '-': n3=n2-n1;
		            break;  
		  case '*': n3=n2*n1;
		            break;
		  case '/': n3=n2/n1;
		            break;	
		  case '^': n3=pow(n2,n1);
		            break;
		  case '%': n3=n2%n1;
		            break;
		  default: cout<<"\nUndefined symbol";
		           exit(1);			 			  								        
	   }
	   Push(n3);
	 }
	 s++;
  }
}

void show()
{ nn=Pop();
  cout<<"\nThe Result is:\t"<<nn;
}
int main()
{ cout<<"\Enter the Postfix expression:\t";
  gets(Postfix);
  setexpr(Postfix);
  Postfix_eval();
  show();
  return 0;
}
