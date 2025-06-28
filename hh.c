#include <cs50.h>
#include <stdio.h>

int main(void)
{
int oll[]={1,3,4,2,5};
for(int i =0;i<6;i++)
{
    for(int j=0;j<oll[i];j++)
    if(j<oll[i])
    {
printf("%i",j);

    }
    printf("\n");
}
return 0;
}