#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
    int data;
    struct node*next;
}node;

void free3(node*list)
{
    while(list != NULL)
    {
    node*temp=list;
    list=list->next;
    free(temp);
}
}
int main(void)
{
    int add;
    int number;
    node*list=NULL;
    printf("NB:");
    scanf("%i",&number);

    for(int i=1;i<number;i++)
    {
        printf("NB %i: ",i);
        scanf("%i",&add);

    node*n=malloc(sizeof(node));
    n->data=add;
    n->next=NULL;
    n->next=list;
    list=n;

}




int i=0;
node*current=list;
while(current!=NULL)
{
    printf("NB %i:%i\n",i,current->data);
    current=current->next;
    i++;
}
 free3(list);
   return 0;
}
