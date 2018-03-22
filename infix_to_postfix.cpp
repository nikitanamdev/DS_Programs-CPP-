// program to convert infix expression to postfix
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int size=50;
char infix[size],postfix[size],stack[size];
int top=-1;
int precedence(char ch);
char Pop();
char Topelement();
void Push(char ch);
int braces(char *);
int main()
{ char ele,elem,st[2];
  int prep,pre,popped,j=0,chk=0;
  strcpy(postfix," ");
  cout<<"\nEnter the infix expression-\t";
  gets(infix);
  chk=braces(infix);
  if(chk!=0)
  { cout<<"\nUnbalanced no. of braces.\nExtra";
    cout<<(chk==1?" left braces":" right braces");
    cout<<"\n";
    exit(1);
  } 
  for(int i=0;infix[i]!='\0';i++)
  { if(infix[i]!='(' && infix[i]!=')' && infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^')
    postfix[j++]=infix[i];
    else if(infix[i]=='(')
   { elem=infix[i];
     Push(elem);
   }
   else if(infix[i]==')')
   { while((popped=Pop())!='(')
     postfix[j++]=popped;
   }
   else 
   { elem=infix[i];
     pre=precedence(elem);
     
     ele=Topelement();
     prep=precedence(ele);
     if(pre>prep)
     Push(elem);
     else
     { while(prep>=pre)
      { if(ele=='#')
        break;
        popped=Pop();
        ele=Topelement();
        postfix[j++]=popped;
        prep=precedence(ele);
	  }
	  Push(elem);
	  
	 }
   }
  }
  while((popped=Pop())!='#')
  postfix[j++]=popped;
  postfix[j]='\0';
  cout<<"\nPostfix: "<<postfix<<endl;
  return 0;
  }
  
  int precedence(char ch)
  { switch(ch)
    { case'^': return 5;
      case'/': return 4;
      case'*': return 4;
      case'+': return 3;
      case'-': return 3;
      default: return 0;
	}
  }
  char Pop()
  { char ret;
    if(top!=-1)
    { ret=stack[top];
      top=top-1;
      return ret;
	}
	else 
	return '#';
  }
  char Topelement()
  { char ch;
    if(top!=-1)
    ch=stack[top];
    else ch='#';
    return ch;
  }
  void Push(char ch)
  { if(top!=size-1)
    { top++;
      stack[top]=ch;
	}
  }
  int braces(char *s)
  { int leftbr,rightbr;
    leftbr=rightbr=0;
    for(int i=0;s[i]!='\0';i++)
    { if(s[i]=='(') leftbr++;
      else if(s[i]==')') rightbr++;
      
	}
	if(leftbr==rightbr) return 0;
	else if(leftbr>rightbr) return 1;
	else return -1;
  }
