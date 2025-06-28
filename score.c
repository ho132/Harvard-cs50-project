#include<stdio.h>
#include<cs50.h>


const int n = 3;
float average(int array[], int length);

int main(void)
{

int score [n] ;

    for(int i = 0;i < n ; i++)

    {
          score [i] = get_int("scores:");
    }

    printf("Average is %f\n",average (score,n));

}

float average (int array[] ,int length)

{

int sum = 0;
for(int y = 0 ;y < length; y++)
{
    sum+= array[y];
}
return sum  / (float) length ;

}

