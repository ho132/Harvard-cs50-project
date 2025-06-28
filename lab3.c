#include<cs50.h>
#include<stdio.h>


int main(int argc , string argv [])
{
    for (int i=0;i<argc ;i++)
    {
        int d =argv[i][0];

        printf("argv[%i][0] is %c\n",i,d);
    }
}