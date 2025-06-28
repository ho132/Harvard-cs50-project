
int main(void)
{
    int *p;#include<stdio.h>
#include<stdlib.h>

    int size;
    printf("enter a size:  ");
    scanf("%i",&size);
   p=malloc(sizeof(int)*size);
    for(int i =0;i<size;i++)
    {
        printf("element %i : ",i+1);
        scanf("%i",p+i);
    }
    for(int i =0 ;i<size;i++)
    {


        printf("element %i :%i\n",i+1,*(p+i));
    }

}
