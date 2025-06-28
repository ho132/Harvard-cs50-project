#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;
int main(void)
{
node *list=NULL;
node *n=malloc(sizeof(struct node));
  if (n == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
  }
n->number=1;
n->next=NULL;
list=n;


n = malloc(sizeof(struct node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }
n->number=2;
n->next=list;
list=n;

n = malloc(sizeof(struct node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;}
n->number=3;
n->next=list;
list=n;

// Free allocated memory before returning
    while (list != NULL) {
        node* temp = list;
        list = list->next;
        free(temp);
    }



return 0 ;
}
