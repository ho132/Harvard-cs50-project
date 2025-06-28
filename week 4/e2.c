#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char wordarray[100];
    char*word;
    printf("enter a word: ");
    scanf("%s",wordarray);
    word=malloc(sizeof(char)*(strlen(wordarray)+1));
    strcpy(word,wordarray);
    printf("%s",word);
free(word);
return 0;
}
