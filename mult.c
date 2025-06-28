#include<cs50.h>
#include<stdio.h>
int mult (int a , int b );


int main(void)
{
    int a,b;

        a=get_int("A: ");
        b=get_int("B:  ");

    int results=mult(a,b);
    printf("Results:  %i\n",results);
    
}

    int mult (int a , int b )
    {
       int mult= a*b;
       return mult;

    }

