#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data){
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLeftBoundary(struct node *root){
  if(root){
    if(root->left){
      printf("%d\n", root->data);
      printLeftBoundary(root->left);
    }
    else if(root->right){
      printf("%d\n", root->data);
      printLeftBoundary(root->right);
    }
  }
}

void printLeaf(struct node *root){
  if(root){
    printLeaf(root->left);
    if(!(root->left) && !(root->right)){
      printf("%d\n", root->data);
    }
    printLeaf(root->right);
  }
}

void printRightBoundary(struct node *root){
  if(root){
    if(root->right){
      printf("%d\n", root->data);
      printRightBoundary(root->right);
    }
    else if(root->left){
      printf("%d\n", root->data);
      printRightBoundary(root->left);
    }
  }
}

void printBoundary(struct node *root){
  if(root){
    printf("%d\n", root->data);
    printLeftBoundary(root->left);
    printLeaf(root->left);
    printLeaf(root->right);
    printRightBoundary(root->right);

  }
}

int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary( root );

    return 0;
}
