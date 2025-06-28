#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string name=get_string("Name:  ");
    int length=strlen(name );

        for (int i=0;i<length;i++)

        if  (name[i] >='a' && name[i]<='z')
{

        printf("Yes");
        return 0;
}

        else

        {
            printf("No\n");
            return 0;
        }

        }


