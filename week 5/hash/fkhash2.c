#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <stdint.h>


#define MAX_NAME  256
#define TABLE_SIZE 10
#define DELETED_NODE ((person*)0xFFFFFFFFFFFFFFFFUL)// magine your computer's memory as a long row of storage boxes, and each box has a unique address. The DELETED_NODE is like a special address (0xFFFFFFFFFFFFFFFFUL) in the memory row, and we're telling the computer that at that special address, there is a pretend box labeled as a person type.
//value like NULL that i know it will never be valid address, SO any pointer that i see that has this value  i know its been deleted
typedef struct
{
    char name[MAX_NAME];
    int age;
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
        else if(hash_table[i]==DELETED_NODE)
        {
printf("\t%i\t-----<deleted>\n",i);
        }
        else
        {
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
     }

}
bool hash_table_insert(person *p)
{
    if(p==NULL)
    {
        return false;
    }
    int index=hash(p->name); //hash value of Name

for(int i = 0; i < TABLE_SIZE; i++)
{
    int try = (i + index) % TABLE_SIZE; //iterate over hash taBle       19%5=(how maNy times does go iNto 19 =3)with remaiNder 4 so =4
      if(hash_table[try] == NULL  || hash_table[try] == DELETED_NODE)
      {                                                   //  40%5=0 //4%5=4
            hash_table[try]=p;   //
            return true;    //The loop iterates through the hash table indices using linear probing.
//For each iteration, it calculates the try_index using (i + index) % TABLE_SIZE.
//It checks if the slot at the calculated index in the hash table is NULL.
//If the slot is NULL, it means the slot is empty, and it inserts the person (p) at that index in the hash table and returns true.
//If the loop completes without finding an empty slot, it returns false, indicating that the hash table is full or there's no available slot for insertion.

//so it keeps goiNg uNtil it fiNd a0 empyty spot aNdd stops at TABLE_SIZE 9
        }

    }

    return false;
  //  if(hash_table[index] != NULL)
    //{
      //  return false; //if the place of Name is Not empty   //WITHOUT CONSIDERING COLLIONSS
    //}
    //hash_table[index]=p;
    //return true;

}
person *hash_table_lookup(char*name)
{
    int index=hash(name);

for(int i = 0; i < TABLE_SIZE; i++)
{
    int try = (i + index) % TABLE_SIZE;
    if(hash_table[try] == NULL )
    {
        return false;
    }
    if(hash_table[try] == DELETED_NODE ) continue;

    if(strncmp(hash_table[try]->name, name,TABLE_SIZE) == 0)

  //  if(hash_table[try] != NULL && strncmp(hash_table[try]->name,name,TABLE_SIZE)==0) //before deleted node
    {
       return  hash_table[try];
     //No loops ,this goNNA Be very fast so its goNNA take coNstaNt TIme No matter the size of hash taBle which is so much faster thaN arrays or liNked list

    }
}

        return NULL;


}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++)
{
    int try = (i + index) % TABLE_SIZE;
    if(hash_table[try] == NULL ) return NULL;
    if(hash_table[try] == DELETED_NODE ) continue;

    if(strncmp(hash_table[try]->name, name,TABLE_SIZE) == 0) {
        // Entry found, delete it
        person *tmp = hash_table[try];
        hash_table[try] = DELETED_NODE;
        return tmp;  // Return the pointer before setting it to NULL
    }
}
        // Entry not found
        return NULL;
}
//Linear Probing
///has made thiNgs very iNefficieNt especially wheN wht we ware lookiNg for isNt iN the taBle we will go through the whole taBle.(before deleted node)

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
//summary, DELETED_NODE is a special value that helps manage deletions in the hash table. It allows the program to differentiate between empty slots, deleted slots, and slots that still contain valid data.
//collision occurs when two different keys hash to the same index or slot in the hash table. Hash functions map keys to indices, and ideally, each key should map to a unique index. However, due to the finite size of the hash table and the potentially infinite set of keys, collisions can occur.
//Instead of setting a slot to NULL upon deletion, it is marked with a special "deleted node" marker.

