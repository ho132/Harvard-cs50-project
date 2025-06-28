#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get length from user
    int n;
    do
    {
     n=get_int("N: ");
    }
    while (n<1);
     //Declare the array
    int array [n];
        //multiplying the elements

        for (int i=0; i<n ;i++)
        {
           array [0]=1;
array[i]=i*2;
        }
        //printing the elements
for (int i=0; i<n ;i++)
        {

        printf("%i\n",array[i]);
}
}