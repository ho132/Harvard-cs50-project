#include<cs50.h>
#include<stdio.h>

int main(void)
{
    string name =get_string("Whats your name ?");

    int n=0;
    while(name[n] != '\0')
    {
        n++;
    }
    printf("%i\n",n);
}