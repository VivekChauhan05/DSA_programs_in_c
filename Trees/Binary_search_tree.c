#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};
struct node *root;

struct node*newnode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void Inorder(struct node*root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->key);
        Inorder(root->right);
    }
}

struct node *Insert(struct node *node,int key)
{
    if(node == NULL)
    {
        
        return newnode(key);
    } 

    if(key < node->key)
    {
        node->left = Insert(node->left,key);
    }

    if(key > node->key)
    {
        node->right  = Insert(node->right,key);
    }
    return node;
}

int minimum(struct node *node)
{
   struct node *temp = node; 
   while(temp->left != NULL)
   {
        temp = temp->left;
   }
   return (temp->key);
}

int maximum(struct node *node)
{
    
   struct node *temp = node; 
   while(temp->right != NULL)
   {
        temp = temp->right;
   }

   return (temp->key);
    
}

void search_value(struct node *root,int value)
{
    struct node *temp = root;
    if(temp == NULL)
    {
        printf("\nThe number doesn't exist in the tree\n");
    }
    if(temp->key == value)
    {
        printf("\nElement is present\n");
    }
    if(temp->key > value)
    {
        search_value(temp->left,value);
    }
    if(temp->key < value)
    {
        search_value(temp->right,value);
    }

}

int main()
{
    struct node*root = NULL;
    root = Insert(root,50);
    Insert(root,30);
    Insert(root,20);
    Insert(root,40);
    Insert(root,70);
    Insert(root,60);
    Insert(root,80);
    Inorder(root);
    printf("\nMaximum value of the given BST is : %d\n",maximum(root));
    printf("Minimum value of the given BST is : %d",minimum(root));
    search_value(root,90);
    return 0;
}
