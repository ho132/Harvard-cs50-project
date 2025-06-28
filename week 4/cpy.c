#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

 int main(void)
 {
    //first
    string na=get_string("l:");
    string t=na;
    t[0]=toupper(t[0]);
    printf("%s\n%s\n",na,t);


    //second
    char*a=get_string("a:");
    char* b=a;

    if(strlen(b)>0)
    {
    b[0]=toupper(b[0]);
    }
    printf("%s\n%s\n",a,b);


    //correct
    char*z=get_string("a:");
    //if the user write a lot
    if(z==NULL)
    {
        return 1;
    }
    char* s=malloc(strlen(z)+1);
    //if we ask for too much memory
    if(s==NULL)
    {
        return 2;
    }
   int n=strlen(z)+1;

    for(int i =0;i<n;i++)  //instead of doing these 3 lines we can just do strcpy(z,s);
    {
        s[i]=z[i];
    }

    if(strlen(s)>0)
    {
    s[0]=toupper(s[0]);
    }
    printf("%s\n%s\n",z,s);
    free(s);
    return 0;
 }