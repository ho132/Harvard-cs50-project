#include<cs50.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
    string name[]={"Lama","johm"};
    string nb[]={"56432","35643"};
    string namee=get_string("Whats the name?"  );
    for(int i =0;i<2;i++)
    {
        if(strcmp(name[i],namee)==0)
        {
            printf("Found %s\n",nb[i]);
            return 0;
        }
    }
 printf("No\n");
 }