#include<cs50.h>
#include<stdio.h>
int sum (int a , int b );


int main(void)

    {
        //prompt user for length
        int a,b,c;
        do
{

      a = get_int("Side1:  ");
      b = get_int("Side2:  ");
      c = get_int("Side3:  ");
}
while (a<1 || b<1 || c<1);

      int h = sum(a ,  b );
      if (h>c)
      {
        printf("True\n");
      }
      else
      {
        printf("False\n");
      }
    }




int sum (int a , int b )
{
  int  sum=a + b;
    return sum;
}

