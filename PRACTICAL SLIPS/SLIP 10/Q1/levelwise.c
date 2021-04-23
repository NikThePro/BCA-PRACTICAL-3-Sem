#include <stdio.h>
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* getNewNode(int data) {
  /* dynamically allocate memory for a new node */
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  
  /* populate data in new Node */
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
   
  return newNode;
}
 
/*
This function returns below tree
            1
           / \
         2    3
        / \    \
       4  5    7
      / \
     8  9
*/
struct node* generateBTree(){
    // Root Node
    struct node* root =  getNewNode(1);
 
    root->left = getNewNode(2);
    root->right = getNewNode(3);
 
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->right = getNewNode(7);
  
    root->left->left->left = getNewNode(8);
    root->left->left->right = getNewNode(9);
     
    return root;
}
 
/* Returns maximum of two given numbers */
int getMax(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}
/*
Returns height of a bianry tree
*/
int getHeight(struct node *root){
    int leftHeight, rightHeight;
    if(root == NULL)
        return 0;
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
     
    return getMax(leftHeight, rightHeight) + 1;
}
/* 
   Prints all node at a particular level. It does pre Order 
   traversal and keeps track of the current level.
   If current level is equal to the level, it prints current node
*/
void printNodesAtLevel(struct node* root, int currentLevel, int level) {
   
  if(root == NULL) {
      return;   
  }  
  if(currentLevel == level) {
      printf(" %d ", root->data);
      return;
  }
              
  printNodesAtLevel(root->left, currentLevel+1, level);
  printNodesAtLevel(root->right, currentLevel+1, level);
}
 
/* Printd nodes of binary tree level wise */
void levelOrderTraversal(struct node* root){
    /* Find the height of tree */
    int i, height = getHeight(root);
    /* Iterate from level 0 to height-1 and 
 print one level at a time */
    for(i = 0; i < height; i++){
     printNodesAtLevel(root, 0, i);
     printf("\n");
    }
}
 
int main() {
    struct node *root = generateBTree();    
     
    /*Printing all nodes level wise*/
    levelOrderTraversal(root);
     
    getchar();
    return 0; 
}