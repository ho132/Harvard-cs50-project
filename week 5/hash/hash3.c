#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <stdint.h>


#define MAX_NAME  256
#define TABLE_SIZE 10

typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next;
}
person;

person*hash_table[TABLE_SIZE];  //o, the line person* hash_table[TABLE_SIZE]; is creating an array of pointers, which is commonly used to implement a hash table. Each element in the array represents a "bucket" in the hash table, and it can hold the address of a person struct or be NULL if no person is stored in that bucket.


unsigned int hash(char *name)
{
unsigned int hash_value=0;
int l=strlen(name);
for(int i=0;i<l;i++)
{
hash_value+=name[i];
hash_value=(hash_value*name[i])% TABLE_SIZE;
}
    return hash_value;
}


void init_hash_table()
{
   for(int i=0;i<TABLE_SIZE;i++)
   {
    hash_table[i]=NULL;
   }//table is empty
}

void print_table()
{
     for(int i=0;i<TABLE_SIZE;i++)
     {
        if(hash_table[i]==NULL)
        {
            printf("\t%i\t----\n",i);      // \t%i\t makes space Before aNd after NB  = 42 =
        }

        else
        {
            printf("\t%i\t",i);
            person*tmp=hash_table[i];
            while( tmp !=NULL)
            {
                printf("%s - ",tmp->name);
                tmp=tmp->next;
            }
            printf("\n");
        }
     }
printf("End\n");
}
bool hash_table_insert(person *p)
{
    if(p==NULL)
    {
        return false;
    }
    int index=hash(p->name); //hash value of Name         //[0] -> NULL
                                                           //[1] -> (p: Bob, next: (p: Jane, next: NULL))  hash("Bob") = 1 (collision with "Jane")
                                                         // [2] -> (p: John, next: NULL)
                                                       // [3] -> (p: Alice, next: NULL)

    p->next=hash_table[index];
    hash_table[index]=p; //this means that the person represented by p is being added to the linked list at the specified index. If there were already elements in the linked list at this index (due to collisions), this operation makes the newly inserted person the new head of the linked list.
       //
            return true;
  }
person *hash_table_lookup(char*name)
{
    int index=hash(name);
     person *tmp = hash_table[index]; // Initializes a temporary pointer tmp to the head of the linked list at the computed index in the hash table.


    while(tmp != NULL&& strncmp(tmp->name,name,MAX_NAME)!=0)

    {
       tmp=tmp->next; //The code enters a while loop, which continues as long as tmp is not NULL (indicating the end of the linked list) and the names do not match. The loop iterates through the linked list at the specified index, searching for a person with the specified name.
//Inside the loop, the pointer tmp is updated to point to the next node in the linked list.

    }

return tmp;//finally, the function returns the pointer tmp, which either points to the node with the matching name or is NULL if no matching name was found in the linked list at the specified hash index.


}

person *hash_table_delete(char *name)
{
  int index=hash(name);
     person *tmp = hash_table[index];

person*prev=NULL;
    while(tmp != NULL&& strncmp(tmp->name,name,MAX_NAME)!=0)

    {
        prev=tmp;
       tmp=tmp->next;
    }
    if(tmp==NULL) return NULL;
    if(prev==NULL)
    {
        //deleting the head
        hash_table[index]=tmp->next;
    }
    else
    {
prev->next=tmp->next; // prev is not NULL, it means that tmp is not the head of the linked list; it's somewhere in the middle or the end.
//Update the next pointer of the node before tmp (prev->next) to skip tmp. Now, prev->next points to the node that comes after tmp.
//This effectively removes tmp from the linked list.
    }

return tmp;


}

int main(void)
{
    init_hash_table();
    print_table();

person jacob = {
        .name = "jacob",
        .age = 25  // Assign the desired age
    };
person fg = {
        .name = "fg",
        .age = 34  // Assign the desired age
    };
person lama = {
        .name = "lama",
        .age = 16  // Assign the desired age
    };

person janna={.name="janna",.age=76};
person sarah={.name="sarah",.age=65};
person robert={.name="robert",.age=23};
person kate={.name="kate",.age=44};
person sasrah={.name="sarah",.age=55};
person eliza={.name="eliza",.age=12};



    hash_table_insert(&jacob);
    hash_table_insert(&fg);
    hash_table_insert(&lama);
    hash_table_insert(&janna);
    hash_table_insert(&sarah);
    hash_table_insert(&robert);
    hash_table_insert(&eliza);
    hash_table_insert(&sasrah);
    hash_table_insert(&kate);
    print_table();


       person *tmp=hash_table_lookup("mopa");
       if(tmp==NULL)
       {
        printf("T fouNd\n");
       }
else
{
    printf(" fouNd %s.\n",tmp->name);
}
 tmp=hash_table_lookup("lama");
       if(tmp==NULL)
       {
        printf("T fouNd\n"); //typical programming conventions, when a lookup operation fails to find the desired item (in this case, a person with a specific name in the hash table), the function often returns a special value to indicate the absence of a valid result. The
       }
else
{
    printf(" fouNd %s.\n",tmp->name);
}



tmp=hash_table_delete("lama");




print_table();
}

