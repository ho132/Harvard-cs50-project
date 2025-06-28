#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MAX_NAME  256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
}
person;

person*hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
unsigned int hash_value=0;
int l=strlen(name); //unsigned: It indicates that the variable will only store non-negative values.
for(int i=0;i<l;i++)
{
hash_value+=name[i];//1+a+m+a=411 (ascii)
//hash_value=hash_value*name[i];//so if we do 0+108*108=11664 aNd theN 11664+97 *97 aNd so oN
hash_value=(hash_value*name[i])% TABLE_SIZE;
}                               //unsigned int hash(char *name): This declares a function named hash that takes a single parameter, a pointer to a character array (string), and returns an unsigned integer (unsigned int).
    return hash_value;


}
int main(void)
{
    void in_it hash table()

    printf("lama => %u\n",hash("lama"));
     printf("mimi => %u\n",hash("mimi"));
     printf("rai => %u\n",hash("rai"));
     return 0;
}
