#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* lchild;
struct node* rchild;
};

struct node* create(struct node*);
void inorder(struct node* );
void preorder(struct node* );
void postorder(struct node* );
void mirror(struct node *);
void main()
{
struct node* root=NULL;
root=(struct node*)create(root);
printf("display" );

printf("\n inorder is");

inorder(root);

printf("\n preorder is");

preorder(root);

printf("\n postorder is");

postorder(root);

printf("\nmirror of tree is\n");
mirror(root);
inorder(root);
getch();
}
struct node* create(struct node* root)
{
struct node* temp,*newn;
int i,size;
clrscr();
printf("enter size");
scanf("%d",&size);
for(i=0;i<size;i++)
{
newn=(struct node*)malloc(sizeof(struct node));
newn->lchild=newn->rchild=NULL;
printf("enter data");
scanf("%d",&newn->data);
if(root==NULL)
{
root=newn;
}
else
{
temp=root;
while(temp!=NULL)
{
if(temp->data>newn->data)
{
if(temp->lchild!=NULL)
{
temp=temp->lchild;
}
else
{
temp->lchild=newn;
break;
}
}
else
{
if(temp->rchild!=NULL)
{
temp=temp->rchild;
}
else
{
temp->rchild=newn;
break;
}
}
} //while
}//else
}//for
return root;
}
void inorder(struct node* root)
{
if(root!=NULL)
{
inorder(root->lchild);
printf("%d ",root->data);
inorder(root->rchild);
}
}
void preorder(struct node* root)
{
if(root!=NULL)
{
printf("%d ",root->data);
preorder(root->lchild);
preorder(root->rchild);
}
}
void postorder(struct node* root)
{
if(root!=NULL)
{
postorder(root->lchild);
postorder(root->rchild);
printf("%d ",root->data);
}
}
void mirror(struct node * root)
{
struct node * temp=root,*temp1;
if(temp)
{
if(temp->lchild)
mirror(temp->lchild);
if(temp->rchild)
mirror(temp->rchild);
temp1=temp->lchild;
temp->lchild=temp->rchild;
temp->rchild=temp1;
}
}