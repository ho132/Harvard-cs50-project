#include<cs50.h>
#include<stdio.h>

int main(void)
{


int y = get_int("Y:  ");
int x ;
{
    x = y ++ ;
    x*=5;
}
        printf("X is %i.\n ",x);

}