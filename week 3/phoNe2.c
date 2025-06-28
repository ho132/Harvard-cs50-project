#include<cs50.h>
#include<stdio.h>
#include<string.h>
typedef struct
{
    string name;
    string nb;
}
person;
int main(void)
{
    person people[2];
    people[0].name="lma";
    people[0].nb="899982";

    people[1].name="kla";
    people[1].nb="092781";

    string mes=get_string("Word: ");
    for(int i =0 ;i<2;i++)
    {
        if(strcmp(people[i].name,mes)==0)
        {
            printf("Found %s\n",people[i].nb);
            return 0;
        }
    }
}