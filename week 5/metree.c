#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}
node;

struct node* createnode(int data)
{

    node*n=malloc(sizeof(node));
    if(n==NULL)
    {
        fprintf(stderr,"error\n");
    }
    n->left=n->right=NULL;
    n->data=data;
    return n;
}

struct node*insert(struct node*root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
     if(data<root->data)
     {
        root->left=insert(root->left,data);

      }
       else if (data>root->data)
     {
        root->right=insert(root->right,data);

     }
return root;
}

 void order(struct node*root)
{
    if(root != NULL)
    {
        order(root->left);
        printf("- %d - ",root->data);
        order(root->right);
    }
}
int main(void)
{
     node*root=NULL;

     root=insert(root,50);
     insert(root ,100);
     insert(root ,45);
     insert(root,150);
     insert(root,30);
     printf("IN ORDER: ");
     order(root);
     printf("\n");
     return 0;
}


