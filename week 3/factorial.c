#include<cs50.h>
#include<stdio.h>
int factorial(int nb);
int main(void)
{
int n=get_int("NB:  ");
printf("%i\n",factorial(n));
}
int factorial(int nb)
{
    if(nb==1)
    {
        return 1;
    }
    return nb * factorial(nb-1);
}