#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//this is the function
typedef struct node {
    int key;
    char *data;
    int size;
    struct node *left;
    struct node *right;
} node;

node *search(node *root, int key) {
    if (root == NULL)
        return NULL;
    if (key == root->key)
        return root;
    if (key > root->key)
        return search(root->right, key);
    return search(root->left, key);
}

char *search_key(int key, node *root) {
    node *req = search(root, key);
    if (req == NULL)
        return NULL;
    return req->data;
}

int Sizeof(node *root) {
    return (root == NULL) ? 0 : root->size;
}

node *insert(node *root, int key, char *data) {

    if (root == NULL) {

        node *newNode = malloc(sizeof(node));
        newNode->key = key;
        newNode->size = 1;
        newNode->data = calloc(strlen(data) + 2, sizeof(char));
        strcpy(newNode->data, data);
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (key == root->key) {
        strcpy(root->data, data);
    } else if (key > root->key)
        root->right = insert(root->right, key, data);
    else
        root->left = insert(root->left, key, data);
    root->size = 1 + Sizeof(root->left) + Sizeof(root->right);
    return root;
}

node* getMin(node *root) {
    if (root->left == NULL)
        return root;
    return getMin(root->left);
}

node *getMax(node *root) {
    if (root->right == NULL)
        return root;
    return getMax(root->right);
}

int sum_of_keys(node *root) {
    if (root == NULL)
        return 0;
    return root->key + sum_of_keys(root->left) + sum_of_keys(root->right);
}

void printTree(node *root) {
    if (root == NULL)
        return;
    printf(" %d %s ---", root->key, root->data);
    printTree(root->right);
    printTree(root->left);
}

void printLeft(node *root) {
    if (root != NULL) {
        printLeft(root->left);
        printf("%d ", root->key);
    }
}

void printRight(node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printRight(root->right);
    }
}

void printTopView(node *root) {
    printLeft(root->left);
    printf("%d ", root->key);
    printRight(root->right);
}

node *delMin(node *root) {
    if (root->left == NULL)
        return root->right;
    root->left = delMin(root->left);
    root->size = 1 + Sizeof(root->left) + Sizeof(root->right);
    return root;
}

node *delMax(node *root) {
    if (root->right == NULL)
        return root->left;
    root->right = delMax(root->right);
    root->size = 1 + Sizeof(root->left) + Sizeof(root->right);
    return root;
}

node *deleteNode(node *root, int key) {
    if (root == NULL)
        return root;
    if (key > root->key){
        root->right = deleteNode(root->right, key);
    } else if (key < root->key){
        root->left = deleteNode(root->left, key);
    } else {
        node *temp = root;
        root = getMin(root->right);
        root->right = delMin(temp->right);
        root->left = temp->left;
    }
    root->size = 1 + Sizeof(root->left) + Sizeof(root->right);
    return root;
}

int height(node *root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

void graphicalPrint(node *root, int space) {

	if (root == NULL)
		return;

	space += 10;
	graphicalPrint(root->right, space);

	printf("\n");
	for (int i = 10; i < space; ++i)
		printf(" ");
	printf("%d-%s-%d\n", root->key, root->data, root->size);

	graphicalPrint(root->left, space);
}

int main() {

    node *root = NULL;
    root = insert(root, 5, "");
    root = insert(root, 3, "");
    root = insert(root, 8, "");
    root = insert(root, 2, "");
    root = insert(root, 2, "");
    root = insert(root, 4, "");
    root = insert(root, 6, "");
    root = insert(root, 9, "");
    root = insert(root, 1, "");
    root = insert(root, 7, "");
    root = insert(root, 10, "");

    graphicalPrint(root, 0);
    return 0;
}
