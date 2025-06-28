#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string st[]={"kla","la","klml","kk"};
    string s=get_string("Word:");
    for(int i =0;i<4;i++)
    {

    if(strcmp(st[i],s)==0)
    {
        printf("Found\n");
        return 0 ;
    }
}
printf("Not found\n");
}