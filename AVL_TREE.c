#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree node;
struct tree
{
    int num,height;
    struct tree *left;
    struct tree *right;
};
node *x,*y;
int max(int a, int b);
int height(node *);
node *rightRotate(node *);
node *leftRotate(node *);
int getBalance(node *);
int main()
{
    node *insert(node *,int);
    void preorder(node *);
    
    node *root=NULL;
    int x;
    char ch;
    do
    {
        printf("Enter the value to insert:: ");
        scanf("%d",&x);
        root=insert(root,x);
        printf("Want to continue?.....(y/n): ");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch=='y');
    printf("-----------------------------\n");
    printf("\nNodes in pre-order::\n");
    preorder(root);
    return 0;
}
node *insert(node *root,int x)
{
    if(root==NULL)
    {
        root=(node *)malloc(sizeof(node));
        root->num=x;
        root->left=root->right=NULL;
    }
    else if(root->num > x)
    {
        root->left=insert(root->left,x);
    }
    else if(root->num < x)
    {
        root->right=insert(root->right,x);
    }
    else
    {
        printf("Duplicate!!");
    }
    return(root);
}
int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

node *rightRotate(node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

node *leftRotate(node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->num);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}








