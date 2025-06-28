#include<cs50.h>
#include<stdio.h>
#include<string.h>
typedef struct
{
string name;
string votes;
}
canidate;
int main(void)
{
    canidate  info[2];
    info[0].name="lmlm";
    info[0].votes="10";

    info[1].name="lml";
    info[1].votes="11";

    string can=get_string("Can:  ");
    for(int i =0 ;i<2 ;i++)
    {
    if(strcmp(info[i].name,can)==0)
    {
        printf("%s\n",info[i].votes);
return 0;
    }

}
}