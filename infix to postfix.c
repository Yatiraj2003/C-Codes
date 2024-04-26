#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100
char stack[SIZE];
int top=-1;

void push(char item)
{

  if(top==SIZE-1)
  {
      printf("\n Stack Overflow\n");
  }
  else
  {

      top=top+1;
      stack[top]=item;
  }
}

char pop()
{
    char item;
    if(top<0)
    {
        printf("\n Stack underflow\n Invalid infix expression\n");
        exit(1);
    }
    else
    {
        item=stack[top];
        top=top-1;
        return item;
    }

}
int is_operator(char symbol)
{
    if(symbol=='^' || symbol=='+' ||symbol=='-' || symbol=='/' || symbol=='*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*' || symbol=='/')
    {
        return 2;
    }
    else if(symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixTopostfix(char infix[],char postfix[])
{
    int i,j;
    char item,x;
    push('(');
    strcat(infix,")");
    i=0,j=0;
    item=infix[i];
    while(item!='\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            x=pop();
            while(is_operator(x)==1 && precedence(item)<=precedence(x))
            {
                postfix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix[j]=x;
                j++;
                x=pop();
            }
        }
        else
        {
            printf("\n Invalid Infix expression\n");
            getchar();
            exit(1);
        }
        i++;
        item=infix[i];
    }
    if(top>0)
    {
        printf("\nInvalid infix expression\n");
        getchar();
        exit(1);
    }
    postfix[j]='\0';

}
int main()
{
    char infix[SIZE],postfix[SIZE];
    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only\n");
    printf("Enter the infix expression\n");
    gets(infix);
    infixTopostfix(infix,postfix);
    printf("Postfix expression is: ");
    puts(postfix);
    return 0;
}
