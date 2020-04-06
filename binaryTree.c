#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

struct node* createNode()
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data(-1 to terminate):");
    scanf("%d",&newNode->data);

    if(newNode->data==-1)
        return NULL;
    else
    {
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }
}

struct node* createTree()
{
    struct node* t=createNode();
    if(t==NULL)
        return NULL;
    else
    {
        printf("Create left child to %d:",t->data);
        t->left=createTree();
        printf("Create right child to %d:",t->data);
        t->right=createTree();
        return t;
    }
}

void traverseInorder(struct node* t)
{
    if(t->left!=NULL)
        traverseInorder(t->left);

    printf("%d",t->data);

    if(t->right!=NULL)
        traverseInorder(t->right);
}

void traversePreorder(struct node*t)
{
    printf("%d",t->data);

    if(t->left!=NULL)
        traversePreorder(t->left);

    if(t->right!=NULL)
        traversePreorder(t->right);
}
void traversePostorder(struct node*t)
{
    if(t->left!=NULL)
        traversePostorder(t->left);

    if(t->right!=NULL)
        traversePostorder(t->right);

    printf("%d",t->data);
}
void main()
{
    root=createTree();
    printf("Inorder:");
    traverseInorder(root);
    printf("\nPreorder:");
    traversePreorder(root);
    printf("\nPostorder:");
    traversePostorder(root);
}
