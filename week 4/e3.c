#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int main(void)
{
int size;
printf("Size: ");
scanf("%i",&size);
int *p=malloc(sizeof(int)*size);
for(int i =0;i<size;i++)
{
printf("%p\n",&size);
}
p=realloc(p,size^2*sizeof(int));
for(int i =0;i<size^2;i++)
{
printf("%p\n",&size);
}

}*/
#define BUFFER_SIZE 4087
int main(void)
{

int sen;
char **strings;
printf("sen: ");
scanf("%i",&sen);
strings=malloc(sizeof(char*)*sen);

char buffer[BUFFER_SIZE];

int length=0;
while(getchar() != '\n');

for(int i =0 ;i<sen;i++)
{
    printf("enter %i string :\n",i+1);
    fgets(buffer,BUFFER_SIZE,stdin);
    length=strlen(buffer);
    buffer[length-1]='\0';
    strings[i]=malloc(length*sizeof(char));
    strcpy(strings[i],buffer);
}
    printf("Result:\n");
for(int i=0;i<sen;i++)

{
    printf("string %i:%s\n",i,strings[i]);
}

printf("\n");
}

