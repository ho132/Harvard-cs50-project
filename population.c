#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int start =0;
    do
    {
        start =get_int("Start size:   ");
    }
    while (start< 9);

    int end ;
    do
    {
        end=get_int("End size:  ");
    }
    while (end < start );


    int years =0 ;
    while (start  < end)
    {
        start += start  / 12 ;
        years++;

    }
     printf("Years : %i\n" , years );
}