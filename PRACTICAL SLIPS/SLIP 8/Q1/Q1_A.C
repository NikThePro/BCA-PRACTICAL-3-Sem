#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<stdio.h>
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *insert(struct tree *,int);
void inorder(struct tree *);
struct tree *search(struct tree *);
int main(void) {
	struct tree *root;
	int choice, item,item_no;
	root = NULL;
	clrscr();
	/* rear  = NULL;*/
	do {
		do {
			printf("\n \t 1. Insert in Binary Tree  ");
			printf("\n \t 2. Display The Binary Tree  ");
			printf("\n\t 3. Search and replace ");
			printf("\n\t 4. Exit ");
			printf("\n\t Enter choice : ");
			scanf(" %d",&choice);
			if(choice<1 || choice>5)
			      printf("\n Invalid choice - try again");
		}
		while (choice<1 || choice>7);
		switch(choice) {
			case 1:
				   printf("\n Enter new element: ");
			scanf("%d", &item);
			root= insert(root,item);
			printf("\n root is %d",root->info);
			printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 2:
			printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			
			
			case 3:
				  printf("\n Search and replace operation in binary tree ");
			root=search(root);
			break;
			default:
				   printf("\n End of program ");
		}
		/* end of switch */
	}
	while(choice !=4);
	return(0);
}
struct tree *insert(struct tree *root, int x) {
	if(!root) {
		root=(struct tree*)malloc(sizeof(struct tree));
		root->info = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->info > x)
	     root->left = insert(root->left,x); else {
		if(root->info < x)
			root->right = insert(root->right,x);
	}
	return(root);
}
void inorder(struct tree *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->info);
		inorder(root->right);
	}
	return;
}


/* function to search and replace an element in the binary tree */
struct tree *search(struct tree *root) {
	int no,i,ino;
	struct tree *ptr;
	ptr=root;
	printf("\n Enter the element to be searched :");
	scanf(" %d",&no);
	fflush(stdin);
	while(ptr) {
		if(no>ptr->info)
		     ptr=ptr->right; else if(no<ptr->info)
		     ptr=ptr->left; else
		     break;
	}
	if(ptr) {
		printf("\n Element %d which was searched is found and is = %d",no,ptr->info);
		printf("\n Do you want replace it, press 1 for yes : ");
		scanf(" %d",&i);
		if(i==1) {
			printf("\n Enter new element :");
			scanf(" %d",&ino);
			ptr->info=ino;
		} else
		    printf("\n\t It's okay");
	} else
	   printf("\n Element %d does not exist in the binary tree",no);
	return(root);
}