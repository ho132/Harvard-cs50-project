#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
if(argc != 2 )
{
printf("Usage: ./substitution key\n");
return  1 ;
}
string key = argv[1];
for(int i =0 ;i<strlen(key);i++)
{
for(int j =0 ;j<i;j++)
if(toupper(key[i])==toupper(key[j]))
{
  printf("Repetition of letters.\n");
  return 1 ;
}

if( strlen(key)!=26)
{
printf("Key must be 26 alphabatical characters.\n");
return 1 ;
}
if(!isalpha(key[i]))
{
  printf("Alphabatical characters only.\n");
  return 1 ;
}
}

string plaintext = get_string("Plaintext: ");
for(int i =0 ;i<strlen(key);i++)
{
  if(islower(key[i]))
  {
    key[i]=key[i]-32;
  }
}
printf("ciphertext: ");


for(int z=0;z<strlen(plaintext);z++)
{
  if(isupper(plaintext[z]))
  {
   int pos=plaintext[z]-65;
    printf("%c",key[pos]);
  }
  else if (islower(plaintext[z]))
  {
    int pos=plaintext[z]-97;
    printf("%c",key[pos]+32);
  }
  else
  {
    printf("%c",plaintext[z]);
  }
}
printf("\n");
}
