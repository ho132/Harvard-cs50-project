#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node * next;
}
node;

int main(void)
{
    node*list=NULL;
    node*current=NULL;
    node*n=malloc(sizeof(struct node));
    if(n==NULL)
    {
        fprintf(stderr,"ERROR\n");
        return 1;
    }

    int element;
    printf("Input the number of nodes: ");
    scanf("%i",&element);

    for (int i=0;i<element;i++)
    {
        if(list==NULL)
        {
            list=n;
            current=n;
        }
        else
        {
            current->next=n;
            current=n;
        }
 printf("element - %i: ",i);

        scanf("%i",&current->data+i);

    }

       for(int i=0;i<element;i++)
    {
 printf("element-%i:%i\n",i,current->data);

}

    while (current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
