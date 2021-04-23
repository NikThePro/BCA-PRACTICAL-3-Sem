#include<stdio.h>
#include<conio.h>
#define MAX 30
typedef struct stack
{
char stk[MAX];
int top;
}
STACK;
void init_stack(STACK *sp)
{
sp->top=-1;
}
int is_empty(STACK *sp)
{
return sp->top==-1;
}
void push(STACK *sp,char val)<
{
sp->stk[++sp->top]=val;
}
char pop(STACK *sp)
{
return sp->stk[sp->top--];
}
char peek(STACK *sp)
{
return sp->stk[sp->top];
}
void disp(STACK *sp)
{
int i;
for(i=0;i<=sp->top;i++)
printf("%c",sp->stk[i]);
printf("\n");
}
int priority(char opr)
{
switch(opr)
{
case '^': return 1;
case '*':
case '/': return 2;
case '+':
case '-': return 3;
default: return 4;
}
}
int is_oper(char c)
{
return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}
void in_post(char in[], char post[])
{
STACK opstk;
char symb,topsymb;
int i,j=0;
init_stack(&opstk);
printf("symb\t\tpostfix\t\topstk\n");
for(i=0;in[i]!='\0';i++)
{
symb = in[i];
if(is_oper(symb))
{
while(!is_empty(&opstk) &&
priority(peek(&opstk))<=priority(symb))
post[j++] = pop(&opstk);
push(&opstk,symb);
}
else if(symb== ')')
{
topsymb = pop(&opstk);
while((topsymb=pop(&opstk))!='(')
post[j++]=topsymb;
}
else if(symb == '(')
push(&opstk,symb);
else
post[j++]=symb;
printf("%c\t\t%s\t\t",symb,post);
disp(&opstk);
}
while(!is_empty(&opstk))
{
post[j++]=pop(&opstk);
printf("\t\t%s\t\t",post);
disp(&opstk);
}
}
void main()
{

char infix[MAX],postfix[MAX]="";
clrscr();
printf("Enter a infix epression:");
scanf("%s",infix);
in_post(infix,postfix);
printf("Postfix expression: %s",postfix);
getch();
}
