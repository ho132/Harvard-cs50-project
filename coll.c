#include<cs50.h>
#include<stdio.h>
int coll(int nb);
int main(void)
{
    int n=get_int("NB: ");
    printf("%i\n",coll(n));

}

int coll(int nb)
{
    if (nb==1)
    {
        return 0;

    }
    else if(nb%2==0)
    {
        return 1 + coll(nb/2);

    }
    else
    {
        return  1 +  coll(3 *nb + 1);


    }
}