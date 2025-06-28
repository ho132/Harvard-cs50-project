#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size= get_int("size: ");
    int calls = get_int("calls: ");
    printf("calls is  %i . size is %i\n ", calls ,size );

    if (calls<10)
{
    printf("Call more\n");

}

else if (calls >10)
{
    printf("Thanks for calling\n");
}

}